#include <bits/stdc++.h>
using namespace std;

int N, X;
int seq[100000];
int arr[2000000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> seq[i];
	cin >> X;

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		int n = seq[i];
		if (n >= X)
			continue;

		if (arr[X - n])
			++count;

		arr[n] = 1;
	}

	cout << count;
}	