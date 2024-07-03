#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	while (N--)
	{
		string op;
		cin >> op;

		if (op == "push")
		{
			int data;
			cin >> data;
			s.push(data);
		}
		else if (op == "pop")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (op == "size")
		{
			cout << s.size() << '\n';
		}
		else if (op == "empty")
		{
			cout << s.empty() << '\n';
		}
		else if (op == "top")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}
}