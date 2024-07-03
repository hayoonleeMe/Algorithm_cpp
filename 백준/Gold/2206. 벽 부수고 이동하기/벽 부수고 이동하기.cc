#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
string board[1005];
// [nx][ny][0] : nx, ny까지 벽을 부수지 않고 이동
// [nx][ny][1] : nx, ny까지 벽을 한번 부수고 이동(nx, ny 부수는 것 포함)
int dist[1005][1005][2];
// x, y, 벽 부순 횟수
queue<tuple<int, int, int>> q;

int bfs();

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	cout << bfs();
}

int bfs()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			dist[i][j][0] = dist[i][j][1] = -1;

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
			else if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1)
			{
				dist[nx][ny][1] = dist[x][y][broken] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}

	// (N, M)에 도달 X
	return -1;
}