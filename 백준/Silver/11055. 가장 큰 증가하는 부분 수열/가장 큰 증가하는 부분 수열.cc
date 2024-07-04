#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int d[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i <= N; ++i)
	{
		d[i] = arr[i];
		for (int j = i - 1; j >= 0; --j)
			if (arr[i] > arr[j])
				d[i] = max(d[i], d[j] + arr[i]);
	}
	std::cout << *max_element(d, d + N);
}