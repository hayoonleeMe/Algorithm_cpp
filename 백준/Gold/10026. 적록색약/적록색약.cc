#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, ans1, ans2;
string board[102];
int visited[102][102];

void BFS(int i, int j, int& ans)
{
	++ans;
	queue<pair<int, int>> q;
	visited[i][j] = 1;
	q.push({ i, j });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] != board[i][j] || visited[nx][ny])
				continue;

			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	// 정상
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j])
				continue;
			BFS(i, j, ans1);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		fill(visited[i], visited[i] + N, 0);

		for (int j = 0; j < N; ++j)
			if (board[i][j] == 'G')
				board[i][j] = 'R';
	}

	// 적록색약
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j])
				continue;
			BFS(i, j, ans2);
		}
	}

	cout << ans1 << ' ' << ans2;
}