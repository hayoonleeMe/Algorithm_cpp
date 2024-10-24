#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, z, ret;

bool solve(ll mid) {
	ll n_z = (y + mid) * 100 / (x + mid);
	return z != n_z;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> x >> y;
	z = y * 100 / x;
	ll l = 1, r = 2 * x;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (solve(mid)) {
			ret = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	if (ret) cout << ret;
	else cout << -1;
}