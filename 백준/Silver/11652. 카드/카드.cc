#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	int cnt = 1, maxCnt = 0;
	long long maxValue = arr[0];
	for (int i = 1; i < N; ++i)
	{
		if (arr[i - 1] == arr[i])
			++cnt;

		if (arr[i - 1] != arr[i] || i == N - 1)
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				maxValue = arr[i - 1];
			}
			cnt = 1;
		}
	}

	cout << maxValue;
}