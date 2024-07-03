#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[27];
int visited[27][27];
queue<pair<int, int>> q;
int N, num;
list<int> areas;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] != '1' || visited[i][j])
				continue;

			++num;
			visited[i][j] = 1;
			q.push({ i, j });

			int area = 0;
			while (!q.empty())
			{
				++area;
				pair<int, int> cur = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (board[nx][ny] != '1' || visited[nx][ny])
						continue;

					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			areas.push_back(area);
		}
	}

	areas.sort();
	cout << num << '\n';
	for (int area : areas)
		cout << area << '\n';
}