#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
int N;
int d[1005][10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i <= 9; ++i)
		d[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int sum = 0;
			for (int k = j; k <= 9; ++k)
				sum = (sum + d[i - 1][k]) % mod;
			d[i][j] = sum;

		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; ++i)
		ans = (ans + d[N][i]) % mod;
	cout << ans;
}