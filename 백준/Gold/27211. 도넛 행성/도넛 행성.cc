#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[1005][1005];
bool vis[1005][1005];
queue<pair<int, int>> q;
int ans;

int XClamp(int x)
{
	if (x >= 0)
		return x % N;
	else
		return x + N;
}

int YClamp(int y)
{
	if (y >= 0)
		return y % M;
	else
		return y + M;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (vis[i][j] || board[i][j] == 1)
				continue;

			vis[i][j] = 1;
			q.push({ i, j });
			++ans;

			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = XClamp(cur.X + dx[dir]);
					int ny = YClamp(cur.Y + dy[dir]);

					if (vis[nx][ny] || board[nx][ny] == 1)
						continue;

					vis[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << ans;
}