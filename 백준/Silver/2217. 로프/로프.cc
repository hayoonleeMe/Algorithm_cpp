#include <bits/stdc++.h>
using namespace std;

int N;
int a[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		ans = max(ans, a[N - i] * i);
	}

	cout << ans;
}