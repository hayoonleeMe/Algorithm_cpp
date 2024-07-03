#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M, K;
int board[1002][1002];
bool vis[1002][1002];

void Bfs(int i, int j, int mid)
{
	if (vis[i][j] || mid < board[i][j])
		return;

	queue<pair<int, int>> q;
	q.push({ i, j });
	vis[i][j] = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] || mid < board[nx][ny])
				continue;

			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

bool Solve(int mid)
{
	for (int i = 0; i < N; ++i)
		fill(vis[i], vis[i] + M, 0);

	for (int j = 0; j < M; ++j)
	{
		Bfs(0, j, mid);
	}

	for (int i = 0; i < N; ++i)
	{
		Bfs(i, 0, mid);
		Bfs(i, M - 1, mid);
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (vis[i][j])
				++cnt;

	return cnt >= K;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	int st = 0;
	int en = 1'000'000;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	cout << st;
}