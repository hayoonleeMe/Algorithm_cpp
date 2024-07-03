#include <bits/stdc++.h>
using namespace std;

int T, N;
long long d[105];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	d[1] = 1; d[2] = 1; d[3] = 1;
	for (int i = 4; i <= 100; ++i)
		d[i] = d[i - 3] + d[i - 2];

	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << d[N] << '\n';
	}
}