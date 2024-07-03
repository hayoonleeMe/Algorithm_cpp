#include <bits/stdc++.h>
using namespace std;

set<string> strs;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	for (int i = 1; i <= s.size(); ++i)
		for (int j = 0; j < s.size() - i + 1; ++j)
			strs.insert(s.substr(j, i));

	cout << strs.size();
}