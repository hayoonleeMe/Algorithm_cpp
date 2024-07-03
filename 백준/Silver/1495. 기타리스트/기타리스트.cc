#include <bits/stdc++.h>
using namespace std;

int N, S, M;
int a[52];
bool d[52][1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> S >> M;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	if (S - a[0] >= 0)
		d[0][S - a[0]] = 1;
	if (S + a[0] <= M)
		d[0][S + a[0]] = 1;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (d[i - 1][j])
			{
				if (j - a[i] >= 0)
					d[i][j - a[i]] = 1;
				if (j + a[i] <= M)
					d[i][j + a[i]] = 1;
			}
		}
	}

	for (int i = M; i >= 0; --i)
	{
		if (d[N - 1][i])
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;
}