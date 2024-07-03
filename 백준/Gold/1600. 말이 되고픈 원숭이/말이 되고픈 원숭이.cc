#include <bits/stdc++.h>
#include <random>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int hdx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hdy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int K, W, H;
int board[202][202];
int dist[32][202][202];
queue<tuple<int, int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cin >> board[i][j];
	
	for (int k = 0; k <= K; ++k)
		for (int i = 0; i < H; ++i)
			fill(dist[k][i], dist[k][i] + W, -1);

	dist[0][0][0] = 0;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		q.pop();

		int k, h, w;
		tie(k, h, w) = cur;

		for (int i = 0; i < 4; ++i)
		{
			int nx = h + dx[i];
			int ny = w + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W || k > K)
				continue;
			if (dist[k][nx][ny] >= 0 || board[nx][ny] == 1)
				continue;

			dist[k][nx][ny] = dist[k][h][w] + 1;
			q.push({ k, nx, ny });
		}

		for (int i = 0; i < 8; ++i)
		{
			int nx = h + hdx[i];
			int ny = w + hdy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W || k + 1 > K)
				continue;
			if (dist[k + 1][nx][ny] >= 0 || board[nx][ny] == 1)
				continue;

			dist[k + 1][nx][ny] = dist[k][h][w] + 1;
			q.push({ k + 1, nx, ny });
		}
	}

	int ans = 0x7f7f7f7f;
	for (int k = 0; k <= K; ++k)
		if (dist[k][H-1][W-1] != -1)
			ans = min(ans, dist[k][H - 1][W - 1]);
	if (ans != 0x7f7f7f7f)
		cout << ans;
	else
		cout << -1;
}