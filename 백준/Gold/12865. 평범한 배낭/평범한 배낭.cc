#include <bits/stdc++.h>
using namespace std;

int n, k, w, v;
int dp[100003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> w >> v;
		for (int j = k; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}