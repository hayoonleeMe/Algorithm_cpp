#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M, R, C;
vector<tuple<int, int, int>> room;

int dist[1002][1002];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> R >> C;
	for (int i = 1; i <= N; ++i)
		fill(dist[i], dist[i] + M + 1, -1);
	for (int i = 0; i < R; ++i)
	{
		int a, b, p;
		cin >> a >> b >> p;
		room.push_back({ p, a, b });
	}
	for (int i = 0; i < C; ++i)
	{
		int c, d;
		cin >> c >> d;

		dist[c][d] = 0;
		q.push({ c, d });
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx <= 0 || nx > N || ny <= 0 || ny > M)
				continue;
			if (dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	int ans = 0x7f7f7f7f;

	for (auto cur : room)
	{
		int p, i, j;
		tie(p, i, j) = cur;

		ans = min(ans, dist[i][j] * p);
	}
	cout << ans;
}