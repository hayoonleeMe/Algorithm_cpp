#include <bits/stdc++.h>
using namespace std;
int dl[6] = { 1, -1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, 1, 0, -1, 0 };
int dc[6] = { 0, 0, 0, 1, 0, -1 };
int L, R, C;
int gI, gJ, gK;
string board[32][32];
int dist[32][32][32];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (cin >> L >> R >> C; L != 0 && R != 0 && C != 0; cin >> L >> R >> C)
	{
		queue<tuple<int, int, int>> q;

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				cin >> board[i][j];
				fill(dist[i][j], dist[i][j] + C, -1);

				for (int k = 0; k < C; ++k)
				{
					if (board[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						q.push({ i,j,k });
					}
					else if (board[i][j][k] == 'E')
					{
						gI = i;
						gJ = j;
						gK = k;
					}
				}
			}
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < 6; ++i)
			{
				int nl = get<0>(cur) + dl[i];
				int nr = get<1>(cur) + dr[i];
				int nc = get<2>(cur) + dc[i];

				if (nl < 0 || nl > L || nr < 0 || nr > R || nc < 0 || nc > C)
					continue;
				if (dist[nl][nr][nc] >= 0 || board[nl][nr][nc] == '#')
					continue;

				dist[nl][nr][nc] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push({ nl, nr, nc });
			}
		}

		if (dist[gI][gJ][gK] == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << dist[gI][gJ][gK] << " minute(s).\n";
	}
}