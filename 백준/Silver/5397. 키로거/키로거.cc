#include <bits/stdc++.h>
using namespace std;

int N;
char BEGIN = '#';

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		list<char> str;
		str.push_back(BEGIN);
		list<char>::iterator cursor = str.begin();

		for (char c : s)
		{
			if (c == '<')
			{
				if (*cursor != BEGIN)
					--cursor;
			}
			else if (c == '>')
			{
				if (cursor != --str.end())
					++cursor;
			}
			else if (c == '-')
			{
				if (*cursor != BEGIN)
				{
					cursor = str.erase(cursor);
					--cursor;
				}
			}
			else
			{
				if (cursor != str.end())
					++cursor;
				str.insert(cursor, c);
				--cursor;
			}
		}
		str.pop_front();

		for (auto c : str)
			cout << c;
		cout << '\n';
	}
}