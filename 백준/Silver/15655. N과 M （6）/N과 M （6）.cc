#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int mask[10];

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	for (int i = M; i < N; ++i)
		mask[i] = 1;

	do
	{
		for (int i = 0; i < N; ++i)
			if (!mask[i])
				cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(mask, mask + N));
}