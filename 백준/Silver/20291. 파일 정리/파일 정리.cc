#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		int dot = s.find('.');
		string ex = s.substr(dot + 1, s.size() - dot);
		m[ex]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end());

	for (auto p : v)
		cout << p.first << ' ' << p.second << '\n';
}