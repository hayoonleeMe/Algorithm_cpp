#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		v.push_back(s.substr(i, s.size() - i));

	sort(v.begin(), v.end());
	for (string a : v)
		cout << a << '\n';
}