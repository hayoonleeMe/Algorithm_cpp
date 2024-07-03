#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10005];
int d[10005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	d[1] = arr[1];
	d[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; ++i)
	{
		d[i] = max({ d[i - 1], d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i] }); 
	}

	cout << d[N];
}