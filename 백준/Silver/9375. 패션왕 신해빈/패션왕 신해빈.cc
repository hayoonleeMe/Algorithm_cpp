#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		map<string, int> m;

		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			string s1, s2;
			cin >> s1 >> s2;
			++m[s2];
		}

		int ans = 1;
		for (const pair<string, int>& p : m)
			ans *= (p.second + 1);
		cout << ans - 1 << '\n';
	}
}