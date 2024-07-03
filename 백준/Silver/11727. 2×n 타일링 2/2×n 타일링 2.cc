#include <bits/stdc++.h>
using namespace std;

int N;
const int mod = 10007;
int d[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= N; ++i)
		d[i] = (d[i - 1] + d[i - 2] * 2) % mod;
	cout << d[N];
}