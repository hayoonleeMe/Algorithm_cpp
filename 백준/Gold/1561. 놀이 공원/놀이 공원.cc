#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, ret;
int v[10003];

bool solve(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < m; ++i)
		cnt += mid / v[i];
	return cnt >= n - m;
}

int solve2() {
	ll sum = 0;
	for (int i = 0; i < m; ++i)
		sum += ret / v[i];
	ll cnt = sum + m - n;
	for (int i = m - 1; i >= 0; --i) {
		if (ret % v[i] == 0) {
			if (cnt-- > 0) continue;
			return i + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	if (n <= m) {
		cout << n;
		return 0;
	}
	for (int i = 0; i < m; ++i)
		cin >> v[i];
	ll l = 1, r = 60000000000;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (solve(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << solve2();
}