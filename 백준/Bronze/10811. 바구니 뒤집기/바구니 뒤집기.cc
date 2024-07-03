#include <bits/stdc++.h>
using namespace std;

int N, M, i, j;
int a[102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		a[i] = i;
	while (M--)
	{ 
		cin >> i >> j;
		reverse(a + i, a + j + 1);
	}

	for (int i = 1; i <= N; ++i)
		cout << a[i] << ' ';
}