#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[105];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (M--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		for (int t = i; t <= j; ++t)
			a[t] = k;
	}

	for (int i = 1; i <= N; ++i)
		cout << a[i] << ' ';
}