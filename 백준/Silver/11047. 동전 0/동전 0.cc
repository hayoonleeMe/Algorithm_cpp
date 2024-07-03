#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int a[15];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	for (int i = N - 1; i >= 0; --i)
	{
		ans += K / a[i];
		K %= a[i];
	}
	cout << ans;
}