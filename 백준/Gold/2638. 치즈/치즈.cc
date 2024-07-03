#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[105][105];
int vis[105][105];
queue<pair<int, int>> q;
int ans;

void Bfs()
{
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

			// 치즈면 공기에 접촉하는 횟수 +1
			if (board[nx][ny] == 1)
			{
				++vis[nx][ny];
			}
			else if (!vis[nx][ny])
			{
				vis[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	// 초기 vis 업데이트
	vis[0][0] = 1;
	q.push({ 0, 0 });
	Bfs();

	while (1)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (vis[i][j] >= 2)
				{
					board[i][j] = 0;
					vis[i][j] = 1;
					q.push({ i, j });
				}
			}
		}

		if (q.size() == 0)
			break;

		++ans;
		Bfs();
	}

	cout << ans;
}