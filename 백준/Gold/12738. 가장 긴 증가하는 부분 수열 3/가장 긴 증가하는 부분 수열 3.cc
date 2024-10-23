#include <bits/stdc++.h>
using namespace std;

int n, t, ret;
int v[1000003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		auto pos = lower_bound(v, v + ret, t);
		if (*pos == 0) ++ret;
		*pos = t;
	}
	cout << ret << '\n';
}