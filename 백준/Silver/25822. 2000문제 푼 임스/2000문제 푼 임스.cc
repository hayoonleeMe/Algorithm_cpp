#include <bits/stdc++.h>
using namespace std;

double C;
int coin;
int N;
int a[100'002];
// i=N, j=스트릭 사용 횟수
int d[100'002][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> C;
	coin = C / 0.99;

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	if (a[1] == 0)
		d[1][1] = 1;
	else
		d[1][0] = 1;

	for (int i = 2; i <= N; ++i)
	{
		if (a[i] == 0)
		{
			d[i][0] = 0;
			d[i][1] = d[i - 1][0] + 1;
			d[i][2] = d[i - 1][1] + 1;
		}
		else
		{
			d[i][0] = d[i - 1][0] + 1;
			d[i][1] = d[i - 1][1] + 1;
			d[i][2] = d[i - 1][2] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= coin; ++j)
			ans = max(ans, d[i][j]);

	cout << ans << '\n' << *max_element(a, a + N + 1);
}