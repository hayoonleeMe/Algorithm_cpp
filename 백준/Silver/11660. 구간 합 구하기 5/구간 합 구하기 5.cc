#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1030][1030];
int d[1030][1030];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= N; ++i)
	{
		d[i][1] = a[i][1];
		for (int j = 2; j <= N; ++j)
			d[i][j] = a[i][j] + d[i][j - 1];
	}

	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int ans = 0;
		for (int i = x2; i >= x1; --i)
		{
			ans += d[i][y2];
			if (y1 != 1)
				ans -= d[i][y1 - 1];
		}

		cout << ans << '\n';
	}
}