#include <bits/stdc++.h>
using namespace std;

int T, W;
int t[1005];
int d[1005][35];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T >> W;
	for (int i = 1; i <= T; ++i)
		cin >> t[i];

	for (int i = 1; i <= T; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			d[i][j] = (t[i] == (j % 2 + 1));
			if (j != 0)
				d[i][j] += max(d[i - 1][j], d[i - 1][j - 1]);
			else
				d[i][j] += d[i - 1][j];
		}
	}

	cout << *max_element(d[T], d[T] + W + 1);
}