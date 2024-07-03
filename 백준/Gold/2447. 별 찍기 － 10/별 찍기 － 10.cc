#include <bits/stdc++.h>
using namespace std;

int N;
char board[2200][2200];

void print3x3Star(int i, int j)
{
	board[i][j] = '*';
	board[i][j + 1] = '*';
	board[i][j + 2] = '*';

	board[i + 1][j] = '*';
	board[i + 1][j + 2] = '*';
	
	board[i + 2][j] = '*';
	board[i + 2][j + 1] = '*';
	board[i + 2][j + 2] = '*';
}

void func(int n, int i, int j)
{
	if (n == 3)
	{
		print3x3Star(i, j);
		return;
	}

	func(n / 3, i, j);
	func(n / 3, i, j + n / 3);
	func(n / 3, i, j + 2 * n / 3);

	func(n / 3, i + n / 3, j);
	func(n / 3, i + n / 3, j + 2 * n / 3);

	func(n / 3, i + 2 * n / 3, j);
	func(n / 3, i + 2 * n / 3, j + n / 3);
	func(n / 3, i + 2 * n / 3, j + 2 * n / 3);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board[i][j] = ' ';

	func(N, 0, 0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << board[i][j];
		cout << '\n';
	}
}