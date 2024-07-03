#include <bits/stdc++.h>
using namespace std;

string A;
int d[5005];
const int mod = 1000000;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A;

	if (A[0] != '0')
	{
		d[0] = 1;
		d[1] = 1;
	}

	int an = A.size();
	for (int i = 2; i <= an; ++i)
	{
		if (A[i - 1] != '0')
			d[i] = d[i - 1];

		string s = A.substr(i - 2, 2);
		int t = stoi(s);
		if (s[0] != '0' && t >= 1 && t <= 26)
			d[i] = (d[i] + d[i - 2]) % mod;

		if (d[i] == 0)
		{
			cout << 0;
			return 0;
		}
	}

	cout << d[an];
}