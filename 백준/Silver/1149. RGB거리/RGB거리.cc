#include <bits/stdc++.h>
using namespace std;
const int R = 0;
const int G = 1;
const int B = 2;
int N;
int a[1002][3];
int d[1002][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int r, g, b;
		cin >> r >> g >> b;
		a[i][R] = r; d[i][R] = r;
		a[i][G] = g; d[i][G] = g;
		a[i][B] = b; d[i][B] = b;
	}

	for (int i = 1; i < N; ++i)
	{
		d[i][R] += min(d[i - 1][G], d[i - 1][B]);
		d[i][G] += min(d[i - 1][R], d[i - 1][B]);
		d[i][B] += min(d[i - 1][R], d[i - 1][G]);
	}

	cout << min({ d[N-1][R], d[N-1][G], d[N-1][B] });
}