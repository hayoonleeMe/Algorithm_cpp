#include <bits/stdc++.h>
using namespace std;

int n, k, t;
int dp[10003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		for (int j = t; j <= k; ++j)
			dp[j] += dp[j - t];
	}
	cout << dp[k];
}