#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> m;
list<string> ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		m.insert({ s, 1 });
	}

	for (int i = 0; i < M; ++i)
	{
		string s;
		cin >> s;

		++m[s];
	}

	for (auto p : m)
		if (p.second > 1)
			ans.push_back(p.first);

	cout << ans.size() << '\n';
	for (string s : ans)
		cout << s << '\n';
}