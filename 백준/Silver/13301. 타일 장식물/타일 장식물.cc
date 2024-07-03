#include <bits/stdc++.h>
using namespace std;

int N;
long long d[82];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	d[1] = d[2] = 1;

	for (int i = 3; i <= 81; ++i)
		d[i] = d[i - 1] + d[i - 2];

	long long ans = 2 * d[N + 1] + 2 * d[N];
	cout << ans;
}