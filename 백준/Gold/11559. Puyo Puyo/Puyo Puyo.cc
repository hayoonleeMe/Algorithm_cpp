#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

const int N = 12;
const int M = 6;
string board[12];
bool vis[12][6];
int ans = 0;

void Drop()
{
	for (int j = 0; j < M; ++j)
	{
		for (int i = N - 1; i > 0; --i)
		{
			if (board[i][j] != '.')
				continue;

			int target = i - 1;
			for (; target >= 0 && board[target][j] == '.'; --target);
			if (target < 0)
				break;
			swap(board[i][j], board[target][j]);
		}
	}
}

bool CheckAndBoom()
{
	for (int i = 0; i < N; ++i)
		fill(vis[i], vis[i] + M, 0);

	bool bBoom = false;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == '.' || vis[i][j])
				continue;

			// Check
			vector<pair<int, int>> v;
			v.push_back({ i, j });
			vis[i][j] = 1;
			int cnt = 1;
			int cur = 0;
			while (cur < v.size())
			{
				pair<int, int> p = v[cur++];
				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = p.X + dx[dir];
					int ny = p.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					if (board[nx][ny] != board[p.X][p.Y] || vis[nx][ny])
						continue;

					v.push_back({ nx, ny });
					vis[nx][ny] = 1;
					++cnt;
				}
			}

			// Boom
			if (cnt >= 4)
			{
				bBoom = true;
				for (pair<int, int>& p : v)
					board[p.X][p.Y] = '.';
			}
		}
	}

	return bBoom;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < N; ++i)
		cin >> board[i];

	while (1)
	{
		if (CheckAndBoom())
			++ans;
		else
			break;

		Drop();
	}

	cout << ans;
}