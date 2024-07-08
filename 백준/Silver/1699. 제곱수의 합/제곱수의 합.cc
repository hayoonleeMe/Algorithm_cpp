#include <bits/stdc++.h>
using namespace std;

int N;
int d[100'005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		d[i] = i;
		for (int j = 1; j * j <= i; ++j)
			d[i] = min(d[i], d[i - j * j] + 1);
	}
	cout << d[N];
}