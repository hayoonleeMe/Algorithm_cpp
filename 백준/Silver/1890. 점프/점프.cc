#include <bits/stdc++.h>
using namespace std;

int N;
int a[102][102];
long long d[102][102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> a[i][j];

	d[1][1] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			// x
			for (int ii = 1; ii < i; ++ii)
				if (ii + a[ii][j] == i)
					d[i][j] += d[ii][j];
			// y
			for (int jj = 1; jj < j; ++jj)
				if (jj + a[i][jj] == j)
					d[i][j] += d[i][jj];
		}
	}

	cout << d[N][N];
}