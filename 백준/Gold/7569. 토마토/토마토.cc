#include <bits/stdc++.h>
using namespace std;

#define Z 0
#define X 1
#define Y 2
int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, 0, 1, 0, -1 };
int M, N, H;
int board[100][100][100];
int dist[100][100][100];
queue<tuple<int, int, int>> q;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h)
	{
		for (int n = 0; n < N; ++n)
		{
			for (int m = 0; m < M; ++m)
			{
				cin >> board[h][n][m];
				if (board[h][n][m] == 1)
					q.push({ h,n,m });
				else if (board[h][n][m] == 0)
					dist[h][n][m] = -1;
			}
		}
	}

	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 6; ++i)
		{
			int nh = get<Z>(cur) + dh[i];
			int nx = get<X>(cur) + dx[i];
			int ny = get<Y>(cur) + dy[i];

			if (nh < 0 || nh >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nh][nx][ny] >= 0)
				continue;

			q.push({ nh, nx, ny });
			dist[nh][nx][ny] = dist[get<Z>(cur)][get<X>(cur)][get<Y>(cur)] + 1;
		}
	}

	for (int h = 0; h < H; ++h)
	{
		for (int n = 0; n < N; ++n)
		{
			for (int m = 0; m < M; ++m)
			{
				if (dist[h][n][m] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[h][n][m]);
			}
		}
	}

	cout << ans;
}