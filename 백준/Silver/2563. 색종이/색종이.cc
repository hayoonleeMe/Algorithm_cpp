#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
int board[102][102];
bool isused[102][102];
queue<pair<int, int>> q;

int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;

		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				board[x + i][y + j] = 1;

		q.push({ x, y });
		isused[x][y] = 1;
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		++ans;

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100)
				continue;
			if (isused[nx][ny] || board[nx][ny] == 0)
				continue;

			q.push({ nx, ny });
			isused[nx][ny] = 1;
		}
	}
	cout << ans;
}