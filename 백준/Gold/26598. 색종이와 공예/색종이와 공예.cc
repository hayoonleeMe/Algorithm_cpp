#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;	
string board[1005];
bool vis[1005][1005];
queue<pair<int, int>> q;
// min_x min_y max_x max_y
vector<tuple<int, int, int, int>> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (vis[i][j])
				continue;

			vis[i][j] = 1;
			q.push({ i, j });

			int min_x = i, min_y = j;
			int max_x = i, max_y = j;
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
					if (vis[nx][ny] || board[cur.X][cur.Y] != board[nx][ny])
						continue;
					
					vis[nx][ny] = 1;
					q.push({ nx, ny });

					min_x = min(min_x, nx);
					min_y = min(min_y, ny);
					max_x = max(max_x, nx);
					max_y = max(max_y, ny);
				}
			}

			char mark = board[min_x][min_y];
			for (int i = min_x; i <= max_x; ++i)
			{
				for (int j = min_y; j <= max_y; ++j)
				{
					if (board[i][j] != mark)
					{
						cout << "BaboBabo";
						return 0;
					}
				}
			}
		}
	}

	cout << "dd";
}