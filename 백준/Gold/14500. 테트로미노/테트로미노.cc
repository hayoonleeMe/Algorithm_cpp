#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int board[502][502];

vector<vector<pair<int, int>>> t0 = { { {0, 0}, {0, 1}, {0, 2}, {0, 3} }, { {0,0}, {1,0}, {2,0}, {3,0} } };
vector<vector<pair<int, int>>> t1 = { { {0,0}, {0,1}, {1,0}, {1,1} } };
vector<vector<pair<int, int>>> t2 = { { {0,0}, {1,0}, {2,0}, {2,1} }, { {0,0}, {1,0}, {0,1}, {0,2} }, { {0,0}, {0,1}, {1,1}, {2,1} }, { {0,0}, {1,0}, {1,-1}, {1,-2} },
								 { {0,0}, {1,0}, {2,0}, {2,-1} }, { {0,0}, {0,1}, {0,2}, {1,2} }, { {0,0}, {0,1}, {1,0}, {2,0} }, { {0,0}, {1,0}, {1,1}, {1,2} } };
vector<vector<pair<int, int>>> t3 = { { {0,0}, {1,0}, {1,1}, {2,1} }, { {0,0}, {0,1}, {1,0}, {1,-1} }, 
								 { {0,0}, {1,0}, {1,-1}, {2,-1} }, { {0,0}, {0,1}, {1,1}, {1,2} } };
vector<vector<pair<int, int>>> t4 = { { {0,0}, {0,1}, {0,2}, {1,1} }, { {0,0}, {1,0}, {1,-1}, {2,0} }, { {0,0}, {1,0}, {1,-1}, {1,1} }, { {0,0}, {1,0}, {1,1}, {2,0} } };

int ans;

int GetMaxSum(int i, int j, const vector<vector<pair<int, int>>>& t)
{
	int tot = 0;
	for (const vector<pair<int, int >>& tt : t)
	{
		int sum = 0;
		for (auto& p : tt)
		{
			int nx = i + p.X;
			int ny = j + p.Y;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				sum = -1;
				break;
			}
			sum += board[nx][ny];
		}
		if (sum > 0)
			tot = max(tot, sum);
	}
	return tot;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			ans = max({ ans, GetMaxSum(i,j,t0), GetMaxSum(i,j,t1), GetMaxSum(i,j,t2), GetMaxSum(i,j,t3), GetMaxSum(i,j,t4) });

	cout << ans;
}