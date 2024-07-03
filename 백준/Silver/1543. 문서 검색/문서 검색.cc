#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str, target;
	getline(cin, str);
	getline(cin, target);

	int ans = 0;
	int pos = 0;

	while (pos < str.size())
	{
		int nxt_pos = str.find(target, pos);
		if (nxt_pos == -1)
			break;
		++ans;
		pos = nxt_pos + target.size();
	}
	cout << ans;
}