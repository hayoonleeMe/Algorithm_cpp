#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string s;
int target;
int order;

string p;
unordered_map<char, bool> isused;

void Solve(int k)
{
	if (k == s.size())
	{
		++order;
		if (order == target)
			cout << s << " " << target << " = " << p << '\n';
		return;
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (!isused[s[i]])
		{
			p += s[i];
			isused[s[i]] = 1;
			Solve(k + 1);
			isused[s[i]] = 0;
			p.erase(p.size() - 1, 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> s)
	{
		cin >> target;
		order = 0;
		isused = {};

		Solve(0);
		if (order < target)
			cout << s << " " << target << " = No permutation\n";
	}
}