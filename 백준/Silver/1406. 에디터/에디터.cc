#include <bits/stdc++.h>
using namespace std;

list<char> str;
int M;

// BEGIN a b c d END-cursor(str.end()) dummy
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	for (char c : s)
		str.push_back(c);
	cin >> M;

	list<char>::iterator cursor = str.end();
	//--cursor;
	for (int i = 0; i < M; ++i)
	{
		char c;
		cin >> c;

		switch (c)
		{
		case 'L':
			if (cursor != str.begin())
				--cursor;	
			break;
		case 'D':
			if (cursor != str.end())
				++cursor;
			break;
		case 'B':
			if (cursor != str.begin())
				cursor = str.erase(--cursor);
			break;
		case 'P':
			char data;
			cin >> data;
			str.insert(cursor, data);
			break;
		}
	}


	for (auto c : str)
		cout << c;
}