#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
int N, M;
int board[305][305];
int dist[305][305];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		fill(dist[i] + 1, dist[i] + M + 1, -1);
		for (int j = 1; j <= M; ++j)
			cin >> board[i][j];
	}

	dist[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; ++dir)
		{
			for (int x = 1; x <= board[cur.X][cur.Y]; ++x)
			{
				int nx = cur.X + dx[dir] * x;
				int ny = cur.Y + dy[dir] * x;

				if (nx <= 0 || nx > N || ny <= 0 || ny > M)
					continue;
				if (dist[nx][ny] != -1)
					continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	cout << dist[N][M] - 1;
}