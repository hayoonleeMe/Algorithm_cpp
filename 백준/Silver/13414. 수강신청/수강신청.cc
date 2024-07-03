#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int K, L;
unordered_map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> L;
	for (int i = 0; i < L; ++i)
	{
		string str;
		cin >> str;
		m[str] = i;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; });

	int n = min((int)v.size(), K);
	for (int i = 0; i < n; ++i)
		cout << v[i].first << '\n';
}