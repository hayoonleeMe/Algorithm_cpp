#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int seqI[10];

void func(int k, int st)
{
	if (k == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[seqI[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < N; ++i)
	{
		seqI[k] = i;
		func(k + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	func(0, 0);
}