#include <bits/stdc++.h>
using namespace std;

stack<char> sta;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	bool even = s.size() % 2 == 1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (even && i == s.size() / 2)
			continue;

		if (!sta.empty() && sta.top() == s[i])
			sta.pop();
		else
			sta.push(s[i]);
	}
	cout << sta.empty();
}