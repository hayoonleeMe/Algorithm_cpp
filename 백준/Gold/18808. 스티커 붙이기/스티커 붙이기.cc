#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C;
int board[42][42];
int s[12][12];
int ns[12][12];

bool check(int nR, int nC, int sr, int sc)
{
	if (sr + nR > N || sc + nC > M)
		return false;

	for (int r = 0; r < nR; ++r)
		for (int c = 0; c < nC; ++c)
		{
			if (board[sr + r][sc + c] + ns[r][c] > 1)
				return false;
		}
			
	return true;
}

bool paste(int nR, int nC)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!check(nR, nC, i, j))
				continue;

			for (int r = 0; r < nR; ++r)
				for (int c = 0; c < nC; ++c)
					board[i + r][j + c] += ns[r][c];
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	while (K--)
	{
		cin >> R >> C;
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				cin >> s[r][c];

		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				ns[r][c] = s[r][c];
		int nR = R;
		int nC = C;

		for (int dir = 0; dir < 4; ++dir)
		{
			if (dir != 0)
			{
				for (int r = nR - 1; r >= 0; --r)
					for (int c = 0; c < nC; ++c)
						ns[c][nR - 1 - r] = s[r][c];
				swap(nR, nC);
			}

			// check and paste
			if (paste(nR, nC))
				break;

			for (int r = 0; r < nR; ++r)
				for (int c = 0; c < nC; ++c)
					s[r][c] = ns[r][c];
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 1)
				++ans;
	cout << ans;
}