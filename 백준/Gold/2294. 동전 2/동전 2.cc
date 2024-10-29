#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, t;
int dp[10003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	fill(dp, dp + k + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		for (int j = t; j <= k; ++j)
			dp[j] = min(dp[j], dp[j - t] + 1);
	}
	if (dp[k] == INF) dp[k] = -1;
	cout << dp[k];
}