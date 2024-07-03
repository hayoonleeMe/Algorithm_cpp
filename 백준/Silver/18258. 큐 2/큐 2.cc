#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	string op;
	while (N--)
	{
		cin >> op;

		if (op == "push")
		{
			int val;
			cin >> val;

			q.push(val);
		}
		else if (op == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (op == "size")
			cout << q.size() << '\n';
		else if (op == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "front")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << '\n';
		}
		else if (op == "back")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << '\n';
		}
	}
}