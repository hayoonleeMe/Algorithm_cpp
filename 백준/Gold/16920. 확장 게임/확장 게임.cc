#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, P;
int S[12];
string board[1005];
bool vis[1005][1005];
// x y cnt
queue<tuple<int, int, int>> q[12];
int ans[12];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; ++i)
		cin >> S[i];
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] != '#' && board[i][j] != '.')
			{
				vis[i][j] = 1;
				q[board[i][j] - '0'].push({ i, j, 0 });
				++ans[board[i][j] - '0'];
			}
		}
	}

	while (1)
	{
		bool quit = true;
		for (int i = 1; i <= P; ++i)
		{
			queue<tuple<int, int, int>> nextQ;
			while (!q[i].empty())
			{
				int x, y, cnt;
				tie(x, y, cnt) = q[i].front();
				q[i].pop();
				if (cnt == S[i])
				{
					nextQ.push({ x, y, 0 });
					continue;
				}

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					int ncnt = cnt + 1;

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					if (vis[nx][ny] || board[nx][ny] == '#')
						continue;

					vis[nx][ny] = 1;
					q[i].push({ nx, ny, ncnt });
					++ans[i];
					quit = false;
				}
			}
			q[i] = nextQ;
		}
		if (quit)
			break;
	}

	for (int i = 1; i <= P; ++i)
		cout << ans[i] << ' ';
}