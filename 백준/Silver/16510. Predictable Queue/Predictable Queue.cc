#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[200'002];
long long D[200'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		D[i] = a[i];
		if (i != 0)
			D[i] += D[i - 1];
	}

	while (M--)
	{
		int m;
		cin >> m;

		int i = lower_bound(D, D + N, m) - D;
		if (D[i] == m)
			++i;
		cout << i << '\n';
	}
}