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

	d[0] = 1;
	for (int i = 0; i < N; ++i)
		for (int j = a[i]; j <= K; ++j)
			d[j] += d[j - a[i]];

	cout << d[K];
}