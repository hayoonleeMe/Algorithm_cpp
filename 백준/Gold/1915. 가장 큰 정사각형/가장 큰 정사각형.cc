#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int d[1005][1005];
string a[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (a[i - 1][j - 1] == '0')
				continue;

			d[i][j] = 1 + min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans * ans;
}