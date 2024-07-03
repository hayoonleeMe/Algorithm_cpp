#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		stack<char> s;
		string str;
		cin >> str;

		for (char c : str)
		{
			if (c == '(')
				s.push(c);
			else
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
					s.push(c);
			}
		}

		if (s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}