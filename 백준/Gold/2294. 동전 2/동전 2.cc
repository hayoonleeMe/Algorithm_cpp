#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[105];
int d[10005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	sort(a, a + N);

	for (int i = 1; i <= K; ++i)
	{
		d[i] = 100001;
		for (int j = 0; j < N && a[j] <= i; ++j)
			d[i] = min(d[i], 1 + d[i - a[j]]);
	}

	if (d[K] > 100000)
		cout << -1;
	else
		cout << d[K];
}