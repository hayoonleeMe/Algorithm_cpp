#include <bits/stdc++.h>
using namespace std;

int R, C, W;
long long d[52][52];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C >> W;

	for (int r = 1; r < R + W; ++r)
	{
		for (int c = 1; c <= r; ++c)
		{
			if (c == 1 || c == r)
				d[r][c] = 1;
			else
				d[r][c] = d[r - 1][c - 1] + d[r - 1][c];
		}
	}

	int cL = C;
	for (int r = R; r < R + W; ++r)
	{
		for (int c = C; c <= cL; ++c)
			ans += d[r][c];
		++cL;
	}

	cout << ans;
}