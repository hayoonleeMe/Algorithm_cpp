#include <bits/stdc++.h>
using namespace std;

int N, M;
int mask[10];

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = M; i < N; ++i)
		mask[i] = 1;

	do
	{
		for (int i = 0; i < N; ++i)
			if (!mask[i])
				cout << i + 1 << ' ';
		cout << '\n';
	} while (next_permutation(mask, mask + N));
}