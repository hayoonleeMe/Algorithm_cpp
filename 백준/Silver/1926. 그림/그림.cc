#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[500][500];
int visited[500][500];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
int num, maxArea;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			cin >> board[n][m];

	for (int n = 0; n < N; ++n)
	{
		for (int m = 0; m < M; ++m)
		{
			if (board[n][m] != 1 || visited[n][m])
				continue;

			++num;
			visited[n][m] = 1;
			q.push({ n, m });
			int area = 1;

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
					if (visited[nx][ny] || board[nx][ny] != 1)
						continue;

					visited[nx][ny] = 1;
					q.push({ nx, ny });
					++area;
				}
			}

			maxArea = max(maxArea, area);
		}
	}

	cout << num << '\n' << maxArea << '\n';
}