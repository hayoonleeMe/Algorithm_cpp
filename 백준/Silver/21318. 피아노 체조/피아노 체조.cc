#include <bits/stdc++.h>
using namespace std;

int n, q, x, y;
int a[100'003], dp[100'003];	// dp[n] = n번째 곡까지 연주할 때 실수하는 총 횟수

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i + 1])
			dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}
	cin >> q;
	while (q--) {
		cin >> x >> y;
		cout << dp[y - 1] - dp[x - 1] << '\n';
	}
}