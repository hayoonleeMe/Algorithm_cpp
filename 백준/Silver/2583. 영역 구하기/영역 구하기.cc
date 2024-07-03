#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;
int board[102][102];
int dist[102][102];
queue<pair<int, int>> q;
int num;
list<int> areas;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + M, -1);

	for (int i = 0; i < K; ++i)
	{
		int m, n, mm, nn;
		cin >> m >> n >> mm >> nn;

		for (int k = n; k < nn; ++k)
			for (int l = m; l < mm; ++l)
				board[k][l] = -1;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == -1 || dist[i][j] >= 0)
				continue;

			++num;
			++dist[i][j];
			q.push({ i, j });

			int area = 0;
			while (!q.empty())
			{
				++area;
				pair<int, int> cur = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					if (dist[nx][ny] >= 0 || board[nx][ny] == -1)
						continue;

					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
			areas.push_back(area);
		}
	}

	areas.sort();
	
	cout << num << '\n';
	for (int area : areas)
		cout << area << ' ';
}