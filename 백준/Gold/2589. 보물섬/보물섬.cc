#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
string board[52];
int dist[52][52];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 'L')
				v.push_back({ i, j });
	}

	for (const pair<int, int>& start : v)
	{
		for (int i = 0; i < N; ++i)
			fill(dist[i], dist[i] + M, -1);

		dist[start.X][start.Y] = 0;
		q.push({ start.X, start.Y });

		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			ans = max(ans, dist[cur.X][cur.Y]);

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if (dist[nx][ny] != -1 || board[nx][ny] != 'L')
					continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	cout << ans;
}