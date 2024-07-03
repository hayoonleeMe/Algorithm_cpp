#include <bits/stdc++.h>
using namespace std;

int N, K;
int d[202][202];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i <= N; ++i)
	{
		d[i][1] = 1;
		for (int j = 2; j <= K; ++j)
		{
			for (int k = 0; k <= N; ++k)
			{
				d[i][j] = (d[i][j] + d[k][j - 1]) % 1'000'000'000;
			}
		}
	}

	cout << d[N][K];
}