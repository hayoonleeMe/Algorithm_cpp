#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, t, a, h, damage, ret = 1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> atk;
	while (n--) {
		cin >> t >> a >> h;
		if (t == 1) {
			ll cnt = (ll)ceil((double)h / atk);
			damage += a * (cnt - 1);
		} else {
			atk += a;
			damage = max((ll)0, damage - h);
		}
		ret = max(ret, damage + 1);
	}
	cout << ret;
}