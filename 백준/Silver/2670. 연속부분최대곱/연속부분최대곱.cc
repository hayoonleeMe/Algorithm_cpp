#include <bits/stdc++.h>
using namespace std;

int n;
double v[10003], dp[10003];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(v[i], dp[i - 1] * v[i]);
	}
	printf("%0.3lf", *max_element(dp, dp + n + 1));
}