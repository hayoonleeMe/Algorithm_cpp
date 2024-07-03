#include <bits/stdc++.h>
using namespace std;

int T, N, M;
// N, M
int d[1002][1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	d[1][1] = 1;
	d[2][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;

	for (int n = 3; n <= 1000; ++n)
		for (int m = 2; m <= n; ++m)
			d[n][m] = ((d[n - 1][m - 1] + d[n - 2][m - 1]) % 1'000'000'009 + d[n - 3][m - 1]) % 1'000'000'009;

	while (T--)
	{
		cin >> N >> M;
		cout << d[N][M] << '\n';
	}
}