#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int R, C;
string board[1005];

int dist_f[1005][1005];
queue<pair<int, int>> fire;

int dist_j[1005][1005];
queue<pair<int, int>> jh;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		fill(dist_f[i], dist_f[i] + C, -1);
		fill(dist_j[i], dist_j[i] + C, -1);
		cin >> board[i];

		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'J')
			{
				jh.push({ i, j });
				dist_j[i][j] = 0;
			}
			else if (board[i][j] == 'F')
			{
				fire.push({ i, j });
				dist_f[i][j] = 0;
			}
		}
	}

	// fire
	while (!fire.empty())
	{
		const pair<int, int>& cur = fire.front();
		fire.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist_f[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;

			dist_f[nx][ny] = dist_f[cur.first][cur.second] + 1;
			fire.push({ nx, ny });
		}
	}

	// jihoon
	while (!jh.empty())
	{
		const pair<int, int>& cur = jh.front();
		jh.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << dist_j[cur.first][cur.second] + 1;
				return 0;
			}

			if (dist_j[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist_f[nx][ny] >= 0 && dist_j[cur.first][cur.second] + 1 >= dist_f[nx][ny])
				continue;

			dist_j[nx][ny] = dist_j[cur.first][cur.second] + 1;
			jh.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}