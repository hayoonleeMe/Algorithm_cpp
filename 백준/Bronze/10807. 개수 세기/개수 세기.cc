#include <bits/stdc++.h>
using namespace std;

int N, V;
int arr[100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cin >> V;

	int count = 0;
	for (int i = 0; i < N; ++i)
		if (arr[i] == V)
			++count;

	cout << count;
}