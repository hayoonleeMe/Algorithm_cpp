#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, mx, ans;
int board[102][102];
int visited[102][102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] > mx)
				mx = board[i][j];
		}
	}

	for (int threshold = 0; threshold < mx; ++threshold)
	{
		for (int i = 0; i < N; ++i)
			fill(visited[i], visited[i] + N, 0);

		int num = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] || board[i][j] <= threshold)
					continue;

				++num;
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
						if (visited[nx][ny] || board[nx][ny] <= threshold)
							continue;

						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		ans = max(ans, num);
	}

	cout << ans;
}