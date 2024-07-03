#include <bits/stdc++.h>
using namespace std;

vector<string> crs({ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" });

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	for (const string& cr : crs)
	{
		while (1)
		{
			int pos = str.find(cr);
			if (pos == -1)
				break;
			str.replace(pos, cr.size(), "#");
		}
	}
	cout << str.size();
}