#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20003], b[20003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < m; ++i)
			cin >> b[i];
		sort(b, b + m);
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			int idx = lower_bound(b, b + m, a[i]) - b;
			ret += idx;
		}
		cout << ret << '\n';
	}
}