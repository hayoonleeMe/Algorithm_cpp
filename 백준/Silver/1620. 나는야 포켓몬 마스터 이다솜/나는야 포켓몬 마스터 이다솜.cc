#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, string> um_int;
unordered_map<string, int> um_str;

bool isnumeric(const string& str)
{
	for (const char c : str)
	{
		if (!isdigit(c))
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		um_int.insert({ i + 1, str });
		um_str.insert({ str, i + 1 });
	}

	while (M--)
	{
		string str;
		cin >> str;

		if (isnumeric(str))
		{
			int num = stoi(str);
			if (um_int.find(num) != um_int.end())
			{
				cout << um_int[num] << '\n';
			}
		}
		else
		{
			if (um_str.find(str) != um_str.end())
			{
				cout << um_str[str] << '\n';
			}
		}
	}
}