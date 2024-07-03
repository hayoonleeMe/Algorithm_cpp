#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	do
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		reverse(arr + M, arr + N);
	} while (next_permutation(arr, arr + N));
}