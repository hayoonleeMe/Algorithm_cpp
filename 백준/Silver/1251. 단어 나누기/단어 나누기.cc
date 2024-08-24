#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	string ans;
	ans.resize(str.size());
	for (int i = 0; i < ans.size(); ++i)
		ans[i] = 'z';

	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = i + 1; j < str.size() - 1; ++j)
		{
			string f1 = str.substr(0, i + 1);
			string f2 = str.substr(i + 1, j - i);
			string f3 = str.substr(j + 1, str.size() - (j + 1));
			reverse(f1.begin(), f1.end());
			reverse(f2.begin(), f2.end());
			reverse(f3.begin(), f3.end());

			string newStr = f1 + f2 + f3;
			ans = min(ans, newStr);
		}
	}
	cout << ans;
}