#include <bits/stdc++.h>
using namespace std;

int N;
int a[10'003];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);

	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = i + 1; j <= N - 2; ++j)
		{
			int search = -(a[i] + a[j]);
			ans += upper_bound(a + j + 1, a + N, search) - lower_bound(a + j + 1, a + N, search);
		}
	}
	cout << ans;
}