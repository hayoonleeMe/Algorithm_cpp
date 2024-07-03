#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int a[25];
int d[10005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		cin >> M;
		fill(d + 1, d + M + 1, 0);
		d[0] = 1;

		for (int i = 0; i < N; ++i)
		{
			int c = a[i];
			for (int j = c; j <= M; ++j)
			{
				d[j] += d[j - c];
			}
		}

		cout << d[M] << '\n';
	}
}