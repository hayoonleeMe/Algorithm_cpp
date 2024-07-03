#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int T, M, N, K;
int board[52][52];
int visited[52][52];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			fill(board[i], board[i] + M, 0);
			fill(visited[i], visited[i] + M, 0);
		}

		while (K--)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		queue<pair<int, int>> q;
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] != 1 || visited[i][j] == 1)
					continue;

				++ans;
				visited[i][j] = 1;
				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;
						if (board[nx][ny] != 1 || visited[nx][ny])
							continue;

						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << ans << '\n';
	}
}