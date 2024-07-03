#include <bits/stdc++.h>
using namespace std;

string str;

bool IsLowercase(char c)
{
	return 'a' <= c && c <= 'z';
}

bool IsUppercase(char c)
{
	return 'A' <= c && c <= 'Z';
}

bool SplitByUnderbar(vector<string>& splits)
{
	int pos = 0;
	while (pos < str.size())
	{
		int nxt_pos = str.find('_', pos);
		if (nxt_pos == -1)
			break;

		string split = str.substr(pos, nxt_pos - pos);
		if (!IsLowercase(split[0]))
			return false;
		splits.push_back(split);
		pos = nxt_pos + 1;
	}
	string split = str.substr(pos, str.size() - pos);
	if (!IsLowercase(split[0]))
		return false;
	splits.push_back(split);
	return true;
}

void SplitByUppercase(vector<string>& splits)
{
	int pos = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		// uppercase
		if (IsUppercase(str[i]))
		{
			splits.push_back(str.substr(pos, i - pos));
			pos = i;
		}
		if (i == str.size() - 1)
		{
			splits.push_back(str.substr(pos, i - pos + 1));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	const int offset = (int)'a' - (int)'A';

	cin >> str;

	// c++ -> java
	if (str.find('_') != -1)
	{
		{
			vector<string> splits;
			SplitByUppercase(splits);
			if (splits.size() > 1)
			{
				cout << "Error!";
				return 0;
			}
		}

		vector<string> splits;
		if (!SplitByUnderbar(splits))
		{
			cout << "Error!";
			return 0;
		}
		
		string ans(splits[0]);
		for (int i = 1; i < splits.size(); ++i)
		{
			string& split = splits[i];
			split[0] -= offset;
			ans += split;
		}

		cout << ans;
		return 0;
	}

	// java -> c++
	if (IsLowercase(str[0]))
	{
		vector<string> splits;
		SplitByUppercase(splits);

		string ans(splits[0]);
		for (int i = 1; i < splits.size(); ++i)
		{
			string& split = splits[i];
			split[0] += offset;
			ans += '_';
			ans += split;
		}

		cout << ans;
		return 0;
	}

	// error
	cout << "Error!";
}