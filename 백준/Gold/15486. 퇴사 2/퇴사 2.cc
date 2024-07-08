#include <bits/stdc++.h>
using namespace std;

int N;
int T[1500005];
int P[1500005];
int d[1500005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];

	for (int i = N; i >= 1; --i)
	{
		d[i] = d[i + 1];

		if (i + T[i] - 1 > N)
			continue;

		d[i] = max(d[i + T[i]] + P[i], d[i + 1]);
	}
	cout << *max_element(d, d + N + 1);
}