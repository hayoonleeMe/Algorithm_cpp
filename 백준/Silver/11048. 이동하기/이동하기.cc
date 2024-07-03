#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1002][1002];
int d[1002][1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> a[i][j];
	d[1][1] = a[1][1];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (i - 1 > 0)
				d[i][j] = max(d[i][j], d[i - 1][j] + a[i][j]);

			if (j - 1 > 0)
				d[i][j] = max(d[i][j], d[i][j - 1] + a[i][j]);

			if (i - 1 > 0 && j - 1 > 0)
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + a[i][j]);
		}
	}

	cout << d[N][M];
}

