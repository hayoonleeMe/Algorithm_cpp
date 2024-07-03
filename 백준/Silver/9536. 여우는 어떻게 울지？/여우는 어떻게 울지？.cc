#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int T;

vector<string> Split(const string& str, const string& s)
{
	vector<string> v;
	int pos = 0;
	while (pos < str.size())
	{
		int nxt_pos = str.find(s, pos);
		if (nxt_pos == -1)
			nxt_pos = str.size();
		if (nxt_pos - pos > 0)
		{
			v.push_back(str.substr(pos, nxt_pos - pos));
			pos = nxt_pos + s.size();	
		}
	}
	return v;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	cin.ignore(20000, '\n');
	while (T--)
	{
		string str;
		getline(cin, str);

		unordered_multimap<string, int> um{};

		vector<string> v = Split(str, " ");
		for (int i = 0; i < v.size(); ++i)
		{
			um.insert({ v[i], i });
		}

		string x;
		while (getline(cin, x))
		{
			if (x.find("fox") != -1)
			{
				vector<pair<string, int>> v(um.begin(), um.end());
				sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; });

				for (const pair<string, int>& p : v)
					cout << p.first << ' ';
				break;
			}

			vector<string> ss = Split(x, " goes ");
			um.erase(ss[1]);
		}
		cout << '\n';
	}
}