#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int T, W, H;
string board[1000];
int fire[1000][1000];
int dist[1000][1000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--)
	{
		bool finish = false;
		queue<pair<int, int>> F;
		queue<pair<int, int>> J;
		cin >> W >> H;

		for (int i = 0; i < H; ++i)
		{
			fill(fire[i], fire[i] + W, -1);
			fill(dist[i], dist[i] + W, -1);
			board[i].clear();
		}

		for (int i = 0; i < H; ++i)
			cin >> board[i];

		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (board[i][j] == '*')
				{
					fire[i][j] = 0;
					F.push({ i, j });
				}
				else if (board[i][j] == '@')
				{
					dist[i][j] = 0;
					J.push({ i, j });
				}
			}
		}

		while (!F.empty())
		{
			pair<int, int> cur = F.front();
			F.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W)
					continue;
				if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;

				fire[nx][ny] = fire[cur.X][cur.Y] + 1;
				F.push({ nx, ny });
			}
		}

		while (!J.empty())
		{
			pair<int, int> cur = J.front();
			J.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W)
				{
					cout << dist[cur.X][cur.Y] + 1 << '\n';
					finish = true;
					break;
				}

				if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
					continue;
				if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
					continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				J.push({ nx, ny });
			}
			if (finish)
				break;
		}

		if (!finish)
			cout << "IMPOSSIBLE\n";
	}
}