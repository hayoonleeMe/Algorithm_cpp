#include <bits/stdc++.h>
using namespace std;

int n;
double v[10003], dp[10003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(v[i], dp[i - 1] * v[i]);
	}
	cout << fixed << setprecision(3) << *max_element(dp, dp + n + 1);
}