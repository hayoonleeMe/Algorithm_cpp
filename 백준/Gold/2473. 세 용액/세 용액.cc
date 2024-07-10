#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[5005];
long long ans = 4'000'000'000;
int ans_v[3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			long long n = arr[i] + arr[j];

			int index = lower_bound(arr + j + 1, arr + N, -n) - arr;
			if (index == N)
				--index;
			if (j < index - 1 && abs(n + arr[index - 1]) < abs(n + arr[index]))
				index -= 1;

			if (index != i && index != j)
			{
				if (ans > abs(n + arr[index]))
				{
					ans = abs(n + arr[index]);
					ans_v[0] = arr[i];
					ans_v[1] = arr[j];
					ans_v[2] = arr[index];
				}
			}
		}
	}

	sort(ans_v, ans_v + 3);
	for (int a : ans_v)
		cout << a << ' ';
}
