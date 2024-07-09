#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		sort(arr, arr + N);

		int ans = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				int gap = arr[j] - arr[i];
				if (binary_search(arr, arr + N, arr[j] + gap))
					++ans;
			}
		}

		cout << ans << '\n';
	}
}