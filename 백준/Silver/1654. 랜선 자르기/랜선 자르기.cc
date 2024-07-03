#include <bits/stdc++.h>
using namespace std;

int K, N;
int arr[10'005];

bool Solve(long long x)
{
	long long num = 0;
	for (int i = 0; i < K; ++i)
		num += arr[i] / x;
	return num >= N;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; ++i)
		cin >> arr[i];

	long long st = 1;
	long long en = 0x7fffffff;
	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}