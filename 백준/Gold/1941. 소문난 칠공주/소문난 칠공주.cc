#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int N = 5;
string board[N];
bool isused[N][N];
int ans;
bool visited[N][N];
queue<pair<int, int>> q;

void func(int k, int s, int x, int y)
{
	if (k == 7)
	{
		if (s >= 4)
		{
			for (int i = 0; i < N; ++i)
				fill(visited[i], visited[i] + N, 0);

			q.push({ x, y });
			visited[x][y] = 1;
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (visited[nx][ny] == 1 || isused[nx][ny] == 0)
						continue;

					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}

			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (isused[i][j] && !visited[i][j])
						return;
				}
			}

			++ans;
		}

		return;
	}

	bool nearby = false;
	bool first = true;
	for (int i = x; i < N; ++i)
	{
		int j = first ? y : 0;
		first = false;
		for (; j < N; ++j)
		{
			if (isused[i][j])
				continue;

			isused[i][j] = 1;
			int nx = i + (j + 1) / N;
			int ny = (j + 1) % N;
			int ns = s + (board[i][j] == 'S' ? 1 : 0);
			if (k + 1 == 7)
			{
				nx = i;
				ny = j;
			}
			func(k + 1, ns, nx, ny);
			isused[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < N; ++i)
		cin >> board[i];

	func(0, 0, 0, 0);

	cout << ans;
}