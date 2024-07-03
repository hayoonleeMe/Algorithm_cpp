#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int M, N;
int board[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> q;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int n = 0; n < N; ++n)
	{
		for (int m = 0; m < M; ++m)
		{
			cin >> board[n][m];
			if (board[n][m] == 1)
				q.push({ n, m });
			else if (board[n][m] == 0)
				dist[n][m] = -1;
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] >= 0)
				continue;

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}

	for (int n = 0; n < N; ++n)
	{
		for (int m = 0; m < M; ++m)
		{
			if (dist[n][m] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[n][m]);
		}
	}

	cout << ans;
}