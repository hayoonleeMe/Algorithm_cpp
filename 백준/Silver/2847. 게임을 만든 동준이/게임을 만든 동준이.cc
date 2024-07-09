#include <bits/stdc++.h>
using namespace std;

int N;
int arr[105];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = N - 2; i >= 0; --i)
	{
		if (arr[i] < arr[i + 1])
			continue;

		ans += arr[i] - (arr[i + 1] - 1);
		arr[i] = arr[i + 1] - 1;
	}
	cout << ans;
}