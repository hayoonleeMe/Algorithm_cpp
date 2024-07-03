#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M;
int board[10][10];
// x, y, num
vector<tuple<int, int, int>> cctvs;
// x, y, num, dir
vector<tuple<int, int, int, int>> chosen(70'000);

int dup[10][10];
int ans = 0x7fffffff;

void mark(int x, int y, int d)
{
	pair<int, int> cur = { x, y };
	while (1)
	{
		int nx = cur.first + dx[d];
		int ny = cur.second + dy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			break;
		if (dup[nx][ny] == 6)
			break;

		dup[nx][ny] = 7;
		cur.first = nx;
		cur.second = ny;
	}
}

void func(int k)
{
	if (k == cctvs.size())
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				dup[i][j] = board[i][j];

		for (int i = 0; i < cctvs.size(); ++i)
		{
			int x, y, num, dir;
			tie(x, y, num, dir) = chosen[i];

			if (num == 1)
			{
				int dirs[] = { dir };
				for (int d : dirs)
					mark(x, y, d);
			}
			else if (num == 2)
			{
				int dirs[] = { dir, (dir + 2) % 4 };
				for (int d : dirs)
					mark(x, y, d);
			}
			else if (num == 3)
			{
				int dirs[] = { dir, (dir + 3) % 4 };
				for (int d : dirs)
					mark(x, y, d);
			}
			else if (num == 4)
			{
				int dirs[] = { dir, (dir + 3) % 4, (dir + 2) % 4 };
				for (int d : dirs)
					mark(x, y, d);
			}
			else if (num == 5)
			{
				int dirs[] = { 0, 1, 2, 3 };
				for (int d : dirs)
					mark(x, y, d);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (dup[i][j] == 0)
					++cnt;
		ans = min(ans, cnt);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int x, y, num;
		tie(x, y, num) = cctvs[k];
		chosen[k] = { x, y, num, i };
		func(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6)
				cctvs.push_back({ i, j, board[i][j] });
		}
	}

	func(0);
	cout << ans;
}