#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[1002][1002];
int dist[1002][1002];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + M, -1);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				dist[i][j] = 0;
				q.push({ i, j });
			}
			else if (board[i][j] == 0)
				dist[i][j] = 0;
		}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != 1)
				continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << dist[i][j] << ' ';
		cout << '\n';
	}
}