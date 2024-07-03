#include <bits/stdc++.h>
using namespace std;

int T;
int d[12];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int n = 4; n <= 11; ++n)
		d[n] = d[n - 3] + d[n - 2] + d[n - 1];

	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}