#include <bits/stdc++.h>
using namespace std;

string s;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	int sign = 1;
	int t = 0;
	for (char c : s)
	{
		if (c == '+' || c == '-')
		{
			ans += sign * t;
			t = 0;

			if (c == '-')
				sign = -1;
		}
		else
		{
			t *= 10;
			t += c - '0';
		}
	}
	ans += sign * t;

	cout << ans;
}