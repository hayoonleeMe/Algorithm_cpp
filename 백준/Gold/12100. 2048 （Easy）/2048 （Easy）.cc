#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
vector<int> v(10);
int ans;

void func(int k)
{
	if (k == 5)
	{
		int nb[22][22];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				nb[i][j] = board[i][j];

		for (int k = 0; k < 5; ++k)
		{
			if (v[k] == 0)	// right
			{
				for (int i = 0; i < N; ++i)
				{
					for (int j = N - 1; j > 0;)
					{
						int target = j - 1;
						for (; target >= 0 && nb[i][target] == 0; --target);
						if (target < 0)
							break;

						if (nb[i][j] == 0)
						{
							swap(nb[i][j], nb[i][target]);
							continue;
						}

						if (nb[i][j] == nb[i][target])
						{
							nb[i][j] *= 2;
							nb[i][target] = 0;
						}

						--j;
					}
				}
			}
			else if (v[k] == 1)	// down
			{
				for (int j = 0; j < N; ++j)
				{
					for (int i = N - 1; i > 0;)
					{
						int target = i - 1;
						for (; target >= 0 && nb[target][j] == 0; --target);
						if (target < 0)
							break;

						if (nb[i][j] == 0)
						{
							swap(nb[i][j], nb[target][j]);
							continue;
						}

						if (nb[i][j] == nb[target][j])
						{
							nb[i][j] *= 2;
							nb[target][j] = 0;
						}

						--i;
					}
				}
			}
			else if (v[k] == 2) // left
			{
				for (int i = 0; i < N; ++i)
				{
					for (int j = 0; j < N - 1;)
					{
						int target = j + 1;
						for (; target < N && nb[i][target] == 0; ++target);
						if (target >= N)
							break;

						if (nb[i][j] == 0)
						{
							swap(nb[i][j], nb[i][target]);
							continue;
						}

						if (nb[i][j] == nb[i][target])
						{
							nb[i][j] *= 2;
							nb[i][target] = 0;
						}

						++j;
					}
				}
			}
			else if (v[k] == 3) // up
			{
				for (int j = 0; j < N; ++j)
				{
					for (int i = 0; i < N - 1;)
					{
						int target = i + 1;
						for (; target < N && nb[target][j] == 0; ++target);
						if (target >= N)
							break;

						if (nb[i][j] == 0)
						{
							swap(nb[i][j], nb[target][j]);
							continue;
						}

						if (nb[i][j] == nb[target][j])
						{
							nb[i][j] *= 2;
							nb[target][j] = 0;
						}

						++i;
					}
				}
			}
		}

		for (int i = 0; i < N; ++i)
			ans = max(ans, *max_element(nb[i], nb[i] + N));
		return;
	}

	for (int dir = 0; dir < 4; ++dir)
	{
		v[k] = dir;
		func(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	func(0);
	cout << ans;
}