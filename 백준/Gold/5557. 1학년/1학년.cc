#include <bits/stdc++.h>
using namespace std;

int N;
int a[102];
long long d[102][21];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	d[0][a[0]] = 1;
	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			if (d[i - 1][j] > 0)
			{
				if (j + a[i] <= 20)
					d[i][j + a[i]] += d[i-1][j];
				if (j - a[i] >= 0)
					d[i][j - a[i]] += d[i-1][j];
			}
		}
	}
	cout << d[N - 2][a[N - 1]];
}