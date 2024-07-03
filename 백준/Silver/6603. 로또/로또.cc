#include <bits/stdc++.h>
using namespace std;

int K;
int arr[15];
int mask[15];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (cin >> K; K != 0; cin >> K)
	{
		for (int i = 0; i < K; ++i)
			cin >> arr[i];
		for (int i = 6; i < K; ++i)
			mask[i] = 1;

		do
		{
			for (int i = 0; i < K; ++i)
				if (!mask[i])
					cout << arr[i] << ' ';
			cout << '\n';
		} while (next_permutation(mask, mask + K));
		cout << '\n';
	}
}