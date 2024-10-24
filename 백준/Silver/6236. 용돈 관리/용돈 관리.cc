#include <bits/stdc++.h>
using namespace std;

int n, m, sum, ret = 1987654321;
int v[100003];

bool solve(int mid) {
	int cnt = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] > mid) return false;
		if (cur < v[i]) {
			++cnt;
			cur = mid;
		}
		cur -= v[i];
	}
	return cnt <= m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	int l = 1, r = sum;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			ret = min(ret, mid);
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ret;
}