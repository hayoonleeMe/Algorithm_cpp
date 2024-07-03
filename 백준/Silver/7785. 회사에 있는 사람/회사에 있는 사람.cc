#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int N;
unordered_set<string> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	while (N--)
	{
		string str1, str2;
		cin >> str1 >> str2;

		if (str2 == "enter")
		{
			s.insert(str1);
		}
		else if (str2 == "leave")
		{
			s.erase(str1);
		}
	}
	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());

	for (const string& str : ans)
		cout << str << '\n';
}