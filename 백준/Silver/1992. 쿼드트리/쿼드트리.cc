#include <bits/stdc++.h>
using namespace std;

int N;
string board[64];

bool chk(int n, int i, int j)
{
	for (int r = i; r < i + n; ++r)
		for (int c = j; c < j + n; ++c)
			if (board[r][c] != board[i][j])
				return false;

	return true;
}

void func(int n, int i, int j)
{
	if (chk(n, i, j))
	{
		cout << board[i][j];
		return;
	}

	cout << '(';

	int half = n / 2;
	func(half, i, j);
	func(half, i, j + half);
	func(half, i + half, j);
	func(half, i + half, j + half);

	cout << ')';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	func(N, 0, 0);
}