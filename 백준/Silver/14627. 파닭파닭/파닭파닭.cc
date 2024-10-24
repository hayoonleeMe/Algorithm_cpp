#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c, ret = 1, sum;
ll v[1000003];

bool solve(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < s; ++i)
		cnt += v[i] / mid;
	return cnt >= c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s >> c;
	ll r = -1;
	for (int i = 0; i < s; ++i) {
		cin >> v[i];
		r = max(r, v[i]);
		sum += v[i];
	}
	ll l = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (solve(mid)) {
			ret = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << sum - ret * c;
}