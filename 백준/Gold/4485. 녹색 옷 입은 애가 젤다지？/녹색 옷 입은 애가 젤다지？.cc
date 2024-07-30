#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
int board[130][130];
int d[130][130];
pair<int, int> pre[130][130];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T = 0;
	for (cin >> N; N != 0; cin >> N)
	{
		++T;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];
		for (int i = 0; i < N; ++i)
			fill(d[i], d[i] + N, 0x7f7f7f7f);

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

		d[0][0] = board[0][0];
		pq.push({ d[0][0], 0, 0 });

		while (!pq.empty())
		{
			int r, i, j;
			tie(r, i, j) = pq.top();
			pq.pop();

			if (d[i][j] != r)
				continue;

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				int nr = board[nx][ny];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (d[nx][ny] <= d[i][j] + nr)
					continue;

				d[nx][ny] = d[i][j] + nr;
				pq.push({ d[nx][ny], nx, ny });
				pre[nx][ny] = { i, j };
			}
		}

		vector<pair<int, int>> path;
		pair<int, int> st = { 0, 0 };
		pair<int, int> cur = { N - 1, N - 1 };
		while (cur != st)
		{
			path.push_back(cur);
			cur = pre[cur.X][cur.Y];
		}
		path.push_back(cur);

		int ans = 0;
		for (auto p : path)
			ans += board[p.X][p.Y];
		cout << "Problem " << T << ": " << ans << '\n';
	}
}