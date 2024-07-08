#include <bits/stdc++.h>
using namespace std;

int T;
int coins[25];
int d[10005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> coins[i];

		int M;  cin >> M;
		fill(d, d + M + 1, 0);

		d[0] = 1;
		for (int i = 0; i < N; ++i)
			for (int j = coins[i]; j <= M; ++j)
				d[j] += d[j - coins[i]];
		cout << d[M] << '\n';
	}
}
