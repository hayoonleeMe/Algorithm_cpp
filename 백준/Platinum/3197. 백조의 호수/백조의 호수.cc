#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int R, C;
string board[1502];
int dist[1502][1502];
int vis[1502][1502];

queue<pair<int, int>> LQ;	// 백조 이동
queue<pair<int, int>> MQ;	// 물 녹음

const int NY = 0;
const int L1 = 1;
const int L2 = 2;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;

	int L = L1;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
		fill(dist[i], dist[i] + C, -1);

		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'L')
			{
				LQ.push({ i, j });
				MQ.push({ i, j });
				dist[i][j] = 0;
				vis[i][j] = L++;
			}
			if (board[i][j] == '.')
			{
				MQ.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	int day = -1;
	bool melt = true;
	while (melt)
	{
		++day;

		if (day > 0)
		{
			// 얼음 녹음
			melt = false;
			queue<pair<int, int>> MTemp;
			while (!MQ.empty())
			{
				auto cur = MQ.front(); MQ.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						continue;
					if (dist[nx][ny] >= 0)
						continue;

					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					MTemp.push({ nx, ny });
					melt = true;

					if (vis[cur.X][cur.Y] != NY)
						LQ.push({ cur.X, cur.Y });
				}
			}
			while (!MTemp.empty())
			{
				MQ.push(MTemp.front());
				MTemp.pop();
			}
		}

		// 백조 이동
		while (!LQ.empty())
		{
			auto cur = LQ.front(); LQ.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					continue;
				if (dist[nx][ny] == -1 || vis[nx][ny] == vis[cur.X][cur.Y])
					continue;

				if (vis[nx][ny] != NY && vis[nx][ny] != vis[cur.X][cur.Y])
				{
					cout << day;
					return 0;
				}

				vis[nx][ny] = vis[cur.X][cur.Y];
				LQ.push({ nx, ny });
			}
		}
	}
}