#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
vector<string> v;
unordered_map<string, int> m;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;
		v.push_back(s);
		m[s] = i;
	}

	int nxt = 0;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;
		int index = m[s];
		m.erase(s);
		if (nxt != index)
			++ans;
		else
			for (nxt += 1; nxt < N && m.find(v[nxt]) == m.end(); nxt += 1);
	}
	cout << ans;
}