#include <bits/stdc++.h>
using namespace std;

int N, M;
string A[52];
string B[52];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
			cin >> A[i];

	for (int i = 0; i < N; ++i)
		cin >> B[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{ 
			if (A[i][j] != B[i][j])
			{
				++ans;
				for (int ii = i; ii < i + 3; ++ii)
				{
					for (int jj = j; jj < j + 3; ++jj)
					{
						if (ii >= N || jj >= M)
						{
							cout << -1;
							return 0;
						}
						A[ii][jj] = (A[ii][jj] == '1') ? '0' : '1';
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (A[i][j] != B[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans;
}