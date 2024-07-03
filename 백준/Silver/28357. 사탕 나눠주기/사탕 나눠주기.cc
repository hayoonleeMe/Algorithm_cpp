#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long a[500'002];

bool Solve(long long x)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i)
		if (a[i] > x)
			sum += a[i] - x;
	return sum <= K;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	long long st = 0;
	long long en = 1e12;
	while (st < en)
	{
		long long mid = (st + en) / 2;
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	cout << st;
}
