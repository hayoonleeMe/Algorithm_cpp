#include <bits/stdc++.h>
using namespace std;

int N;
int board[2200][2200];
int ans[3];

void func(int n, int r1, int c1)
{
	if (n == 0)
		return;

	// 숫자가 같은지 확인
	int t = board[r1][c1];
	for (int i = r1; i < r1 + n; ++i)
	{
		for (int j = c1; j < c1 + n; ++j)
		{
			if (t != board[i][j])
			{
				int off = n / 3;
				func(off, r1, c1);
				func(off, r1, c1 + off);
				func(off, r1, c1 + 2 * off);

				func(off, r1 + off, c1);
				func(off, r1 + off, c1 + off);
				func(off, r1 + off, c1 + 2 * off);

				func(off, r1 + 2 * off, c1);
				func(off, r1 + 2 * off, c1 + off);
				func(off, r1 + 2 * off, c1 + 2 * off);

				return;
			}
		}
	}

	if (t == -1)
		++ans[0];
	else if (t == 0)
		++ans[1];
	else if (t == 1)
		++ans[2];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	func(N, 0, 0);

	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
}