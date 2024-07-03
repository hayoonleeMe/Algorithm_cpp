#include <bits/stdc++.h>
using namespace std;

int N;
int a[1002];
int d[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		d[i] = a[i];
	}

	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= i / 2; ++j)
			d[i] = min(d[i], d[j] + d[i - j]);

	cout << d[N];
}