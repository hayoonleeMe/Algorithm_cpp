#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[1'000'005];

bool solve(long long mid)
{
	long long k = 0;
	for (int i = 0; i < N; ++i)
		if (arr[i] < mid)
			k += mid - arr[i];
	return k <= K;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	long long st = 1;
	long long en = 2'000'000'000;
	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		if (solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}