#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	while (N--)
	{
		stack<char> s;
		string str;
		cin >> str;

		for (char c : str)
		{
			if (s.empty())
			{
				s.push(c);
				continue;
			}

			if (s.top() == c)
				s.pop();
			else
				s.push(c);
		}

		if (s.empty())
			++ans;
	}

	cout << ans;
}