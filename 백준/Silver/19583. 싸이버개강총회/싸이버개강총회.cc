#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
int S, E, Q;
int ans;

int strToSec(const string& str)
{
	int sec = 0;
	sec += 3600 * stoi(str.substr(0, 2));
	sec += 60 * stoi(str.substr(3, 2));
	return sec;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string strS, strE, strQ;
	cin >> strS >> strE >> strQ;
	S = strToSec(strS);
	E = strToSec(strE);
	Q = strToSec(strQ);

	string strSec;
	while (cin >> strSec)
	{
		int sec = strToSec(strSec);
		string name;
		cin >> name;

		if (sec <= S)
			s.insert(name);
		else if (E <= sec && sec <= Q)
		{
			if (s.find(name) != s.end())
			{
				++ans;
				s.erase(name);
			}
		}
	}
	cout << ans;
}