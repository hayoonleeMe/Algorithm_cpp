#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[22];	// l, j
int dp[103];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i].first;
	for (int i = 0; i < n; ++i)
		cin >> v[i].second;
	for (int i = 0; i < n; ++i) {
		for (int j = 100; j > v[i].first; --j) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	cout << dp[100];
}