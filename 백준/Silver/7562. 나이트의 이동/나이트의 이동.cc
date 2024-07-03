#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int T, I;
int board[302][302];
int dist[302][302];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> I;
		for (int i = 0; i < I; ++i)
			fill(dist[i], dist[i] + I, -1);

		queue<pair<int, int>> q;
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		dist[a][b] = 0;
		q.push({ a, b });

		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 8; ++i)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I)
					continue;
				if (dist[nx][ny] >= 0)
					continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}

		cout << dist[c][d] << '\n';
	}
}