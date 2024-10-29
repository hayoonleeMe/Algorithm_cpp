#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
ll dp[33][33];

ll go(int w, int h) {
	if (w == 0 && h == 0) return 1LL;
	ll& ret = dp[w][h];
	if (ret != -1) return ret;
	ret = 0;
	if (w > 0) ret += go(w - 1, h + 1);
	if (h > 0) ret += go(w, h - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (; n > 0; cin >> n)	{
		cout << go(n, 0) << '\n';
	}
}