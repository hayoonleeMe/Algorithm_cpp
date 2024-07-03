#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int W, H;
int board[52][52];
bool vis[52][52];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (1)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; ++i)
		{
			fill(vis[i], vis[i] + W, 0);
			for (int j = 0; j < W; ++j)
				cin >> board[i][j];
		}
			
		int ans = 0;
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (vis[i][j] || !board[i][j])
					continue;

				vis[i][j] = 1;
				q.push({ i, j });
				++ans;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 8; ++dir)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= H || ny < 0 || ny >= W)
							continue;
						if (vis[nx][ny] || !board[nx][ny])
							continue;

						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << ans << '\n';
	}
}