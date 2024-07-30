#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M, K;
int board[1002][1002];
bool used[1002][1002];

struct compare
{
	bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
	{
		return get<0>(a) < get<0>(b);
	}
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> board[i][j];
			if (i == 1 || i == N || j == 1 || j == M)
			{
				pq.push({ board[i][j], i, j });
				used[i][j] = 1;
			}
		}

	}
	cin >> K;

	while (K--)
	{
		int v, i, j;
		tie(v, i, j) = pq.top(); pq.pop();

		cout << i << ' ' << j << '\n';

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = i + dx[dir];
			int ny = j + dy[dir];

			if (nx <= 0 || nx > N || ny <= 0 || ny > M)
				continue;
			if (used[nx][ny])
				continue;

			used[nx][ny] = 1;
			pq.push({ board[nx][ny], nx, ny });
		}
	}
}