#include <bits/stdc++.h>
using namespace std;

int N, T;
int d[1005];
int day[1005];
int m[1005];
int totalM;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		cin >> day[i] >> m[i];
		totalM += m[i];
	}

	for (int i = 0; i < N; ++i)
		for (int j = T; j > 0; --j)
			if (j >= day[i])
			d[j] = max(d[j], d[j - day[i]] + m[i]);

	cout << totalM - *max_element(d, d + T + 1);
}