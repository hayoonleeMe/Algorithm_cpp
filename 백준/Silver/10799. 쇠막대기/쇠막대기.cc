#include <bits/stdc++.h>
using namespace std;

int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	stack<char> s;
	int i = 0;
	while (i < str.size())
	{
		if (str[i] == '(')
		{
			// 레이저
			if (str[i + 1] == ')')
			{
				i += 2;
				ans += s.size();
				continue;
			}
			else
				s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			s.pop();
			++ans;
		}

		++i;
	}

	cout << ans;
}