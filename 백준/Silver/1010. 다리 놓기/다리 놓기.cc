#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long long d[35][35];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			fill(d[i] + 1, d[i] + M + 1, 0);
		for (int i = 1; i <= M; ++i)
			d[1][i] = 1;

		for (int i = 2; i <= M; ++i)
			for (int j = i; j <= M; ++j)
				for (int k = 1; k < j; ++k)
					d[i][j] += d[i - 1][k];

		ans = 0;
		for (int i = 1; i <= M; ++i)
			ans += d[N][i];
		cout << ans << '\n';
	}
}