#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	for (getline(cin, str); str != "."; getline(cin, str))
	{
		stack<char> s;

		bool isFailed = false;
		for (char c : str)
		{
			if (c == '(' || c == '[')
				s.push(c);
			else
			{
				if (c == ')')
				{
					if (s.empty() || s.top() != '(')
					{
						isFailed = true;
						break;
					}
					s.pop();
				}
				else if (c == ']')
				{
					if (s.empty() || s.top() != '[')
					{
						isFailed = true;
						break;
					}
					s.pop();
				}
			}
		}
		if (isFailed || s.size() > 0)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}