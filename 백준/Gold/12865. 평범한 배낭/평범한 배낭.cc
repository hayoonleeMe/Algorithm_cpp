#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[105];
int V[105];
int d[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> W[i] >> V[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = K; j > 0; --j)
		{
			if (j >= W[i])
				d[j] = max(d[j], d[j - W[i]] + V[i]);
		}
	}
	cout << *max_element(d, d + K + 1);
}