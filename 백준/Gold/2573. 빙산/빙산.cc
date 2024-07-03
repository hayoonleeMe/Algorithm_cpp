#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[302][302];
int melted[302][302];
int visited[302][302];
queue<pair<int, int>> q;

bool AllMelted()
{
	for (int i = 1; i < N-1; ++i)
		for (int j = 1; j < M-1; ++j)
			if (board[i][j] != 0)
				return false;

	return true;
}

void After1Year()
{
	for (int i = 1; i < N - 1; ++i)
		fill(melted[i], melted[i] + M, 0);

	for (int i = 1; i < N - 1; ++i)
		for (int j = 1; j < M - 1; ++j)
			for (int k = 0; k < 4; ++k)
				if (board[i + dx[k]][j + dy[k]] == 0)
					++melted[i][j];

	for (int i = 1; i < N - 1; ++i)
		for (int j = 1; j < M - 1; ++j)
			if (melted[i][j])
				board[i][j] = max(0, board[i][j] - melted[i][j]);
}

void Dfs(int i, int j)
{
	visited[i][j] = 1;
	q.push({ i, j });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visited[nx][ny] || board[nx][ny] == 0)
				continue;

			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int ans = 0; !AllMelted(); ++ans)
	{
		for (int i = 0; i < N; ++i)
			fill(visited[i], visited[i] + M, 0);

		int num = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visited[i][j] || board[i][j] == 0)
					continue;

				++num;
				Dfs(i, j);
			}
		}

		if (num >= 2)
		{
			cout << ans;
			return 0;
		}

		After1Year();
	}

	cout << 0;
}