#include <bits/stdc++.h>
using namespace std;

int N;
int T[20];
int P[20];
int d[20];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];

	for (int i = 1; i <= N; ++i)
	{
		if (i + T[i] - 1 <= N)
			d[i] = P[i];
		for (int j = i - 1; j >= 1; --j)
			if (i >= j + T[j] && i + T[i] - 1 <= N)
				d[i] = max(d[i], d[j] + P[i]);
	}
	cout << *max_element(d, d + N + 1);
}
