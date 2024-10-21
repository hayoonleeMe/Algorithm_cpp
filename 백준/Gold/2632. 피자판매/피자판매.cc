#include <bits/stdc++.h>
using namespace std;

int m, n, ret, x, tot_a, tot_b;
int a[1003], b[1003];
vector<int> va, vb;

void makeV(int size, int tot, int v[1003], vector<int>& vv) {
	for (int i = 0; i < size; ++i) {
		int sum = 0;
		for (int j = i; j < size - 1; ++j) {
			sum += v[j];
			vv.push_back(sum);
			vv.push_back(tot - sum);
		}
	}
	vv.push_back(tot);
	sort(vv.begin(), vv.end());
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> x >> m >> n;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		tot_a += a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		tot_b += b[i];
	}
	makeV(m, tot_a, a, va);
	makeV(n, tot_b, b, vb);
	for (int t : va) {
		if (t > x) continue;
		if (t == x) {
			++ret;
		} else {
			int f = upper_bound(vb.begin(), vb.end(), x - t) - lower_bound(vb.begin(), vb.end(), x - t);
			if (f > 0)
				ret += f;
		}
	}
	ret += upper_bound(vb.begin(), vb.end(), x) - lower_bound(vb.begin(), vb.end(), x);
	cout << ret;
}