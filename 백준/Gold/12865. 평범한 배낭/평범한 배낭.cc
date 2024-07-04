#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[105];
int V[105];
int d[105][100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int k = 1; k <= K; ++k)
		{ 
			if (k - W[i] >= 0)
				d[i][k] = max(d[i - 1][k], V[i] + d[i - 1][k - W[i]]);
			else
				d[i][k] = d[i - 1][k];
		}
	}
	cout << d[N][K];
}