#include <bits/stdc++.h>
using namespace std;

int N;
int s[305];
int d[305][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> s[i];

	d[1][1] = s[1]; 
	d[1][2] = s[1];

	for (int i = 2; i <= N; ++i)
	{
		d[i][2] = d[i - 1][1] + s[i];
		d[i][1] = s[i] + max(d[i - 2][1], d[i - 2][2]);
	}

	cout << max(d[N][1], d[N][2]);
}