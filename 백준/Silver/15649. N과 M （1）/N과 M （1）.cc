#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		arr[i] = i + 1;

	do
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		reverse(arr + M, arr + N);
	} while (next_permutation(arr, arr + N));
}