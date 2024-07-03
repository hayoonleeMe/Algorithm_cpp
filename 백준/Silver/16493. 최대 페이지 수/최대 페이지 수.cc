#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
int day[202];
int page[202];
int dp[22][202];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> a >> b;
		day[i] = a;
		page[i] = b;
	}

	for (int d = 1; d <= N; ++d)
	{
		for (int c = 1; c <= M; ++c)
		{
			dp[c][d] = dp[c - 1][d];

			if (d >= day[c])
				dp[c][d] = max(dp[c][d], page[c] + dp[c-1][d-day[c]]);
		}
	}

	cout << dp[M][N];
}