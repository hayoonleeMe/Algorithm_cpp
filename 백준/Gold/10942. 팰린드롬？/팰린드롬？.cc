#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[2005];
int d[2005][2005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		d[i][i] = 1;
	}

	for (int i = 1; i < N; ++i)
		d[i][i + 1] = a[i] == a[i + 1];

	for (int k = 3; k <= N; ++k)
	{
		int i = 1, j = k;
		while (j <= N)
		{
			if (a[i] == a[j] && d[i + 1][j - 1])
				d[i][j] = 1;
			++i;
			++j;
		}
	}

	cin >> M;
	while (M--)
	{
		int s, e;
		cin >> s >> e;

		cout << d[s][e] << '\n';
	}
}