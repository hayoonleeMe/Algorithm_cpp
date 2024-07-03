#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000009;
int T, N;
int d[1000005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 1000000; ++i)
		d[i] = ((d[i - 1] + d[i - 2]) % mod + d[i - 3]) % mod;

	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << d[N] << '\n';
	}
}