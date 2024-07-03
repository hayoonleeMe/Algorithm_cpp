#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;
string board[1005];
int dist[1005][1005][15];
queue<tuple<int, int, int>> q;

int bfs();

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j)
			fill(dist[i][j], dist[i][j] + K + 1, -1);
	}

	cout << bfs();
}

int bfs()
{
	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == N - 1 && y == M - 1)
			return dist[x][y][broken];
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1)
			{
				dist[nx][ny][broken] = dist[x][y][broken] + 1;
				q.push({ nx, ny, broken });
			}
			else if (board[nx][ny] == '1' && broken <= K && dist[nx][ny][broken + 1] == -1)
			{
				dist[nx][ny][broken + 1] = dist[x][y][broken] + 1;
				q.push({ nx, ny, broken + 1 });
			}
		}
	}

	return -1;
}