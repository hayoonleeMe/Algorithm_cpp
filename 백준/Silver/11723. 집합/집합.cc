#include <bits/stdc++.h>
using namespace std;

int M;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M;
	while (M--)
	{
		string op;
		cin >> op;

		if (op == "add")
		{
			int x;
			cin >> x;
			s.insert(x);
		}
		else if (op == "remove")
		{ 
			int x;
			cin >> x;
			set<int>::iterator it;
			it = s.find(x);
			if (it != s.end())
				s.erase(it);
		}
		else if (op == "check")
		{ 
			int x;
			cin >> x;
			set<int>::iterator it;
			it = s.find(x);
			if (it != s.end())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "toggle")
		{ 
			int x;
			cin >> x;
			set<int>::iterator it;
			it = s.find(x);
			if (it != s.end())
				s.erase(it);
			else
				s.insert(x);
		}
		else if (op == "all")
		{
			s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (op == "empty")
		{
			s.clear();
		}
	}
}