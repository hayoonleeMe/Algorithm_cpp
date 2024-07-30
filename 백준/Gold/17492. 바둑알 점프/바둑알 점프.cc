#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[13][13];
vector<pair<int, int>> v;

bool ans;

pair<int, int> dirs[9] = { {0,0}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };

void Solve(int k)
{
	if (k == 1)
	{
		ans = true;
		return;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		auto cur = v[i];

		if (board[cur.X][cur.Y] != 2)
			continue;

		for (auto dir : dirs)
		{
			int nx = cur.X + dir.X;
			int ny = cur.Y + dir.Y;

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] != 2)
				continue;

			int nnx = nx + dir.X;
			int nny = ny + dir.Y;
			if (nnx < 0 || nnx >= N || nny < 0 || nny >= N)
				continue;
			if (board[nnx][nny] != 0)
				continue;

			board[nx][ny] = 0;
			board[cur.X][cur.Y] = 0;
			board[nnx][nny] = 2;
			v[i] = { nnx, nny };

			Solve(k - 1);

			board[nx][ny] = 2;
			board[cur.X][cur.Y] = 2;
			board[nnx][nny] = 0;
			v[i] = cur;

			if (ans)
				return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				v.push_back({ i, j });
		}

	Solve(v.size());

	if (ans)
		cout << "Possible";
	else
		cout << "Impossible";
}