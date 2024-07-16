#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[102];
int d[100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	fill(d, d + K + 1, 0x7f7f7f7f);
	d[0] = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = K; j >= arr[i]; --j)
		{
			if (j - arr[i] != 0x7f7f7f7f)
				d[j] = min(d[j], d[j - arr[i]] + 1);
		}
	}
	if (d[K] == 0x7f7f7f7f)
		d[K] = -1;
	cout << d[K];
}
