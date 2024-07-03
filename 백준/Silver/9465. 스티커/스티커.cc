#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[3][100005];
int d[3][100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int i = 0; i < 3; ++i)
			fill(d[i], d[i] + N, 0);

		for (int i = 1; i <= 2; ++i)
			for (int j = 1; j <= N; ++j)
				cin >> arr[i][j];

		for (int i = 1; i <= N; ++i)
		{
			d[0][i] = max({ d[0][i - 1], d[1][i - 1], d[2][i - 1] });
			d[1][i] = arr[1][i] + max(d[0][i - 1], d[2][i - 1]);
			d[2][i] = arr[2][i] + max(d[0][i - 1], d[1][i - 1]);
		}

		int ans = 0;
		for (int i = 0; i < 3; ++i)
			ans = max(ans, d[i][N]);
		cout << ans << '\n';
	}
}