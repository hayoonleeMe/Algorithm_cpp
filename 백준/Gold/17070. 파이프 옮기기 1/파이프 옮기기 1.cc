#include <bits/stdc++.h>
using namespace std;

int N;
int board[20][20];
// i행 j열에 도달하는 경우의수 0:가로 1:세로 2:대각
int d[20][20][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];
	
	d[1][2][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 3; j <= N; ++j)
		{
			// 벽 긁으면 안됨
			if (board[i][j] != 1)
			{
				d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][2];
				d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];

				if (board[i-1][j] != 1 && board[i][j-1] != 1)
					d[i][j][2] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
			}
		}
	}

	cout << d[N][N][0] + d[N][N][1] + d[N][N][2];
}