#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	char op = NULL;
	string s;
	int ans, temp, c;
	for (int i = 0; i < str.size(); ++i)
	{
		c = str[i];
		if (c != '-' && c != '+')
			s.push_back(c);
		else
		{
			temp = stoi(s);
			s.clear();

			if (op == NULL)
			{
				ans = temp;
				op = c;
			}
			else
			{
				// 55 - 50 +
				if (op == '-')
					ans -= temp;
				else
				{
					ans += temp;
					op = c;
				}
			}
		}
	}
	// 40
	temp = stoi(s);
	if (op == NULL)
		ans = temp;
	else
	{
		if (op == '-')
			ans -= temp;
		else
			ans += temp;
	}

	cout << ans;
}

