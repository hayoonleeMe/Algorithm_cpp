#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[2005];
int d[2005][2005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	for (int i = 1; i <= N; ++i)
	{
		d[i][i] = 1;
		if (arr[i] == arr[i - 1])
			d[i - 1][i] = 1;
	}

	for (int gap = 2; gap < N; ++gap)
	{
		for (int i = 1; i <= N - gap; ++i)
		{
			int s = i, e = i + gap;
			if (arr[s] == arr[e] && d[s + 1][e - 1])
				d[s][e] = 1;
		}
	}

	cin >> M;
	while (M--)
	{
		int S, E;
		cin >> S >> E;
		cout << d[S][E] << '\n';
	}
}
