#include <bits/stdc++.h>
using namespace std;

int n, m, c, p;
float fm, fp;
int dp[10003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> fm;
	for (; n > 0; cin >> n >> fm) {
		m = (int)(fm * 100 + 0.0005);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			cin >> c >> fp;
			p = (int)(fp * 100 + 0.0005);
			for (int j = p; j <= m; ++j) {
				dp[j] = max(dp[j], dp[j - p] + c);
			}
		}
		cout << dp[m] << '\n';
	}
}