#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int q;
unordered_map<string, int> um;

int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;

	while (q--)
	{
		string name; 
		char t;
		cin >> name; cin >> t;

		if (t == '+')
			um[name]++;
		else
		{
			// 출근x 퇴근o
			if (um[name] == 0)
				++ans;
			// 출근o 퇴근o
			else
				um[name]--;
		}
	}

	// 출근o 퇴근x
	for (auto m : um)
		ans += m.second;

	cout << ans;
}