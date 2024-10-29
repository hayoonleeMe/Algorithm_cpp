#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n;
int dp[1000003];
vector<int> path;

void go(int here) {
	cout << here << ' ';
	if (here == 1) return;
	if (here % 3 == 0 && dp[here] == dp[here / 3] + 1) go(here / 3);
	else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1) go(here / 2);
	else if (dp[here] == dp[here - 1] + 1) go(here - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	fill(dp, dp + n + 1, INF);
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n] << '\n';
	go(n);
}