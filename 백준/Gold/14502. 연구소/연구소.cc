#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[10][10];
bool vis[10][10];
vector<pair<int, int>> virus;
pair<int, int> newWalls[3];

int bfs()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 0)
				vis[i][j] = 0;
			else if (board[i][j] == 1)
				vis[i][j] = 1;

	for (const pair<int, int>& p : newWalls)
		vis[p.X][p.Y] = 1;

	queue<pair<int, int>> q;
	for (const pair<int, int>& p : virus)
	{
		vis[p.X][p.Y] = 1;
		q.push({ p.X, p.Y });
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny])
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	int safe = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (!vis[i][j])
				++safe;
	return safe;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	int ans = 0;
	int a = 0, b = 1, c = 2;
	for (; a < N * M - 2; ++a)
	{
		if (board[a / M][a % M] != 0)
		{
			++b; ++c;
			continue;
		}

		for (; b < N * M - 1; ++b)
		{
			if (board[b / M][b % M] != 0)
			{
				++c;
				continue;
			}

			for (; c < N * M; ++c)
			{
				if (board[c / M][c % M] != 0)
				{
					continue;
				}

				newWalls[0] = { a / M, a % M };
				newWalls[1] = { b / M, b % M };
				newWalls[2] = { c / M, c % M };

				ans = max(ans, bfs());
			}

			c = b + 2;
		}

		b = a + 2;
		c = a + 3;
	}

	cout << ans;
}