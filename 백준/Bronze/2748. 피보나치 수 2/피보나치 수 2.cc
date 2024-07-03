#include <bits/stdc++.h>
using namespace std;

int N;
long long d[100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= N; ++i)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[N];
}