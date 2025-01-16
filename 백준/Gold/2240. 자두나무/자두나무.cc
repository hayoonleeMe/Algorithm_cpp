#include <bits/stdc++.h>
using namespace std;

int t, w;
int v[1003];
int dp[1003][33];

int go(int tt, int ww) {
	if (tt > t) return 0;
	if (ww > w) return 0;
	int& ret = dp[tt][ww];
	if (ret != -1) return ret;
	int correct = (int)(v[tt] == (ww % 2) + 1);
	ret = max(go(tt + 1, ww), go(tt + 1, ww + 1)) + correct;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> t >> w;
	for (int i = 1; i <= t; ++i)
		cin >> v[i];
	v[0] = -1;
	cout << go(0, 0);
}