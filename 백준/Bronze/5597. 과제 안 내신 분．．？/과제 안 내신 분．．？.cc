#include <bits/stdc++.h>
using namespace std;

bool a[31];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 28; ++i)
	{
		int n; cin >> n;
		a[n] = 1;
	}

	for (int i = 1; i <= 30; ++i)
		if (!a[i])
			cout << i << '\n';
}