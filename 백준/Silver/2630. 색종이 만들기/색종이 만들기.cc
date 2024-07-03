#include <bits/stdc++.h>
using namespace std;

int N;
int board[130][130];
int ans[2];

bool allMatch(int n, int i, int j)
{
	int c = board[i][j];
	for (int r = i; r < i + n; ++r)
		for (int w = j; w < j + n; ++w)
			if (board[r][w] != c)
				return false;

	return true;
}

void func(int n, int i, int j)
{
	if (n == 0)
		return;

	int c = board[i][j];
	if (allMatch(n, i, j))
		++ans[c];
	else
	{
		int half = n / 2;
		func(half, i, j);
		func(half, i, j + half);
		func(half, i + half, j);
		func(half, i + half, j + half);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	func(N, 0, 0);

	cout << ans[0] << '\n' << ans[1];
}