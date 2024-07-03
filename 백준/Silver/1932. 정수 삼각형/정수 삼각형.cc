#include <bits/stdc++.h>
using namespace std;

int N;
int arr[502][502];
int d[502][502];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> arr[i][j];

	d[1][1] = arr[1][1];
	for (int i = 2; i <= N; ++i)
	{
		d[i][1] = arr[i][1] + d[i - 1][1];
		d[i][i] = arr[i][i] + d[i - 1][i - 1];

		for (int j = 2; j < i; ++j)
			d[i][j] = arr[i][j] + max(d[i - 1][j], d[i - 1][j - 1]);
	}

	int ans = d[N][1];
	for (int i = 2; i <= N; ++i)
		ans = max(ans, d[N][i]);
	cout << ans;
}