#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, L, R;
int board[52][52];
bool vis[52][52];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	while (1)
	{
		bool transfer = false;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (vis[i][j])
					continue;

				// 연합 생성
				vector<pair<int, int>> v;

				vis[i][j] = ans + 1;
				v.push_back({ i, j });
				int sum = board[i][j], cnt = 1;
				int idx = 0;
				while (idx < v.size())
				{
					pair<int, int> cur = v[idx++];

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						if (vis[nx][ny])
							continue;

						int gap = abs(board[cur.X][cur.Y] - board[nx][ny]);
						if (gap >= L && gap <= R)
						{
							sum += board[nx][ny];
							++cnt;

							vis[nx][ny] = ans + 1;
							v.push_back({ nx, ny });
						}
					}
				}

				// 인구 이동
				if (cnt > 1)
				{
					int uni = sum / cnt;
					for (const pair<int, int>& p : v)
						board[p.X][p.Y] = uni;
					transfer = true;
				}
			}
		}

		if (transfer)
		{
			++ans;
			for (int i = 0; i < N; ++i)
				fill(vis[i], vis[i] + N, 0);
		}
		else
			break;
	}

	cout << ans;
}