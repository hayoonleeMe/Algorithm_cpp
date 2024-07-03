#include <bits/stdc++.h>
using namespace std;

int N, j, c;
double d[1002];
int sum[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	cin >> d[0];
	sum[0] += d[0];

	for (int i = 1; i < N; ++i)
	{
		int t; cin >> t;
		sum[0] += t;
	}

	cin >> j >> c;

	for (int i = 1; i <= c; ++i)
	{
		d[i] = d[i - 1] + j * (d[i - 1] / sum[i - 1]);
		sum[i] = sum[i - 1] + j;
	}

	cout << fixed << setprecision(9) << d[c];
}