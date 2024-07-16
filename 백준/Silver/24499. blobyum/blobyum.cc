#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100'002];
int d[200'005];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	int i = 1;
	for (; i <= N; ++i)
	{
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}

	for (; i <= N + K - 1; ++i)
		d[i] = d[i - 1] + arr[i % N];

	for (int i = 1; i <= N; ++i)
		ans = max(ans, d[i + K - 1] - d[i - 1]);

	cout << ans;
}
