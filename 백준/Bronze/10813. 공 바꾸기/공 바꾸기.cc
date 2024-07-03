#include <bits/stdc++.h>
using namespace std;

int a[102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		a[i] = i;

	while (M--)
	{
		int i, j;
		cin >> i >> j;
		swap(a[i], a[j]);
	}

	for (int i = 1; i <= N; ++i)
		cout << a[i] << ' ';
}