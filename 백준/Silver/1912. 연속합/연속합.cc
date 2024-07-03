#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100005];
int d[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i <= N; ++i)
		d[i] = max(d[i], d[i - 1] + arr[i]);

	cout << *max_element(d + 1, d + N + 1);
}