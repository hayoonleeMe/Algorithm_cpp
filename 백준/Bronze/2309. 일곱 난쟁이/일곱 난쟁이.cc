#include <bits/stdc++.h>
using namespace std;

int a[14];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; ++i)
		cin >> a[i];
	sort(a, a + 9);

	do
	{
		int sum = 0;
		for (int i = 0; i < 7; ++i)
			sum += a[i];
		if (sum == 100)
		{
			sort(a, a + 7);
			for (int i = 0; i < 7; ++i)
				cout << a[i] << '\n';
			return 0;
		}
	} while (next_permutation(a, a + 9));
}