#include <bits/stdc++.h>
using namespace std;

string s, ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	getline(cin, s);
	ans = s;

	for (int i = 0; i < s.size(); ++i)
	{
		if (isalpha(s[i]))
		{
			if (isupper(s[i]))
			{
				int newC = s[i] + 13;
				if (newC > 'Z')
					newC -= 26;
				ans[i] = newC;
			}
			else
			{
				int newC = s[i] + 13;
				if (newC > 'z')
					newC -= 26;
				ans[i] = newC;
			}
		}
	}
	cout << ans;
}