#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;
	stack<char> s;

	int mul = 1, ans = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			s.push(str[i]);
			mul *= (str[i] == '(') ? 2 : 3;
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				cout << 0;
				return 0;
			}

			if (str[i - 1] == '(')
				ans += mul;
			mul /= 2;
			s.pop();
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				cout << 0;
				return 0;
			}

			if (str[i - 1] == '[')
				ans += mul;
			mul /= 3;
			s.pop();
		}
	}

	if (s.empty())
		cout << ans;
	else
		cout << 0;
}