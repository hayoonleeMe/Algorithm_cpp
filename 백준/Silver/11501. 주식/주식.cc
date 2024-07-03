#include <bits/stdc++.h>
using namespace std;

int T, N;
int a[1'000'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> a[i];

		long long ans = 0;

		int mx = a[N - 1];
		for (int i = N - 2; i >= 0; --i)
		{
			if (a[i] < mx)
				ans += mx - a[i];
			else
				mx = a[i];
		}
		
		cout << ans << '\n';
	}
}