#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[7][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int s, y;
		cin >> s >> y;
		++arr[y][s];
	}

	int count = 0;
	for (int y = 1; y <= 6; ++y)
	{
		for (int s = 0; s <= 1; ++s)
		{
			if (arr[y][s] == 0)
				continue;

			count += arr[y][s] / K;
			if (arr[y][s] % K)
				++count;
		}
	}

	cout << count;
}