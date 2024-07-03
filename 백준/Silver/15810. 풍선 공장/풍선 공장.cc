#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1'000'002];

bool Solve(long long x)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i)
		sum += x / a[i];
	return sum >= M;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	long long st = 1;
	long long en = 1'000'000'000'000;
	long long ans;
	while (st < en)
	{
		long long mid = (st + en) / 2;
		if (Solve(mid))
		{
			en = mid;
			ans = mid;
		}
		else
			st = mid + 1;
	}
	cout << ans;
}