#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100'005];
int d[100'005][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	d[0][0] = -1005;
	d[0][1] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		d[i][0] = max(d[i - 1][0], d[i - 1][1]);
		d[i][1] = max(arr[i], d[i - 1][1] + arr[i]);
	}
	cout << max(d[n - 1][0], d[n - 1][1]);
}