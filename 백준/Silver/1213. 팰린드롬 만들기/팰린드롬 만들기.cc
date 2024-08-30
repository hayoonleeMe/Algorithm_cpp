#include <bits/stdc++.h>
using namespace std;

string str;
int a[30], cur;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> str;
	for (char c : str)
		a[c - 65]++;

	bool isodd = false;
	for (int i = 0; i < 26; ++i)
	{
		while (a[i])
		{
			if (a[i] % 2 == 1)
			{
				if (isodd)
				{
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				isodd = true;
				str[str.size() / 2] = i + 65;
				a[i]--;
			}
			else
			{
				str[cur] = i + 65;
				str[str.size() - 1 - cur] = i + 65;
				a[i] -= 2;
				++cur;
			}
		}
	}
	cout << str;
}