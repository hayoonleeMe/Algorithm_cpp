#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
string board[3005];
int dist[3005][3005];
queue<pair<int, int>> q;
pair<int, int> three, four, five;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		fill(dist[i], dist[i] + m, -1);

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == '2')
			{
				dist[i][j] = 0;
				q.push({ i, j });
			}
			else if (board[i][j] == '3')
				three = { i, j };
			else if (board[i][j] == '4')
				four = { i, j };
			else if (board[i][j] == '5')
				five = { i, j };
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == '1' || dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	int ans = 0x3f3f3f3f;

	int ans_three = dist[three.X][three.Y];
	if (ans_three != -1)
		ans = min(ans, ans_three);

	int ans_four = dist[four.X][four.Y];
	if (ans_four != -1)
		ans = min(ans, ans_four);

	int ans_five = dist[five.X][five.Y];
	if (ans_five != -1)
		ans = min(ans, ans_five);

	if (ans == 0x3f3f3f3f)
		cout << "NIE";
	else
		cout << "TAK\n" << ans;
}