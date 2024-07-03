#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
// [{1,1}, {N,N}]
vector<pair<int, int>> board[105][105];
bool light[105][105];
bool vis[105][105];
queue<pair<int, int>> q;
int x, y, a, b;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (M--)
	{
		cin >> x >> y >> a >> b;
		board[x][y].push_back({ a, b });
	}

	// 1,1
	light[1][1] = 1;
	vis[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		// 스위치 모두 켜기
		for (const pair<int, int>& s : board[cur.X][cur.Y])
		{
			if (vis[s.X][s.Y])
				continue;

			// 인접 체크
			for (int dir = 0; dir < 4; ++dir)
			{
				if (vis[s.X + dx[dir]][s.Y + dy[dir]])
				{
					vis[s.X][s.Y] = 1;
					q.push({ s.X, s.Y });
					break;
				}
			}
			light[s.X][s.Y] = 1;
		}

		// 이동
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx <= 0 || nx > N || ny <= 0 || ny > N)
				continue;
			if (vis[nx][ny] || !light[nx][ny])
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (light[i][j])
				++ans;

	cout << ans;
}