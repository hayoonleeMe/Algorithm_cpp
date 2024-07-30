#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[13][13];
vector<pair<int, int>> v;

bool ans;

pair<int, int> dirs[8] = { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, { -1,-1}, {-1,0}, {-1,1} };

void Solve(int k)
{
	if (k == 1)
	{
		ans = true;
		return;
	}

	for (auto cur : v)
	{
		for (auto dir : dirs)
		{
			int nx = cur.X + dir.X;
			int ny = cur.Y + dir.Y;

			if (nx <= 0 || nx > N || ny <= 0 || ny > N)
				continue;
			if (board[nx][ny] != 2)
				continue;

			int nnx = nx + dir.X;
			int nny = ny + dir.Y;
			if (nnx <= 0 || nnx > N || nny <= 0 || nny > N)
				continue;
			if (board[nnx][nny] != 0)
				continue;

			board[nx][ny] = 0;
			board[cur.X][cur.Y] = 0;
			board[nnx][nny] = 2;

			Solve(k - 1);

			board[nx][ny] = 2;
			board[cur.X][cur.Y] = 2;
			board[nnx][nny] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				v.push_back({ i, j });
		}

	Solve(v.size());

	if (ans)
		cout << "Possible";
	else
		cout << "Impossible";
}