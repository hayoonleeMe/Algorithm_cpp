#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
string board[105];
// 벽뿌 횟수, -1이면 미방문
int cnt[105][105];
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		fill(cnt[i], cnt[i] + M, -1);
		cin >> board[i];
	}

	cnt[0][0] = 0;
	dq.push_back({ 0, 0 });

	while (!dq.empty())
	{
		pair<int, int> cur = dq.front();
		dq.pop_front();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (cnt[nx][ny] != -1)
				continue;

			// 벽X
			if (board[nx][ny] == '0')
			{
				cnt[nx][ny] = cnt[cur.X][cur.Y];
				dq.push_front({ nx, ny });
			}
			// 벽O
			else
			{
				cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
				dq.push_back({ nx, ny });
			}
		}
	}

	cout << cnt[N - 1][M - 1];
}