#include <bits/stdc++.h>
using namespace std;

int n, m1, m2, m, c, p1, p2, p;
int dp[10003];

int main() {
	while (1) {
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) return 0;
		m = m1 * 100 + m2;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			scanf("%d %d.%d", &c, &p1, &p2);
			p = p1 * 100 + p2;
			for (int j = p; j <= m; ++j) {
				dp[j] = max(dp[j], dp[j - p] + c);
			}
		}
		printf("%d\n", dp[m]);
	}
}