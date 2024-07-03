#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;
	const int N = str.size();

	int r = N;
	for (; r >= 1; --r)
	{
		if (N % r != 0)
			continue;
		int c = N / r;
		if (r <= c)
			break;
	}
	int c = N / r;

	string ans;
	for (int j = 0; j < r; ++j)
	{
		for (int i = 0; i < c; ++i)
		{
			ans += str[j + i * r];
		}
	}
	cout << ans;
}