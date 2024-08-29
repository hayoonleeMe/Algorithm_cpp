#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[30];
vector<char> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;
		cnt[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] >= 5)
			v.push_back(i + 'a');
	}

	if (v.empty())
		cout << "PREDAJA";
	else
	{
		sort(v.begin(), v.end());
		for (char c : v)
			cout << c;
	}
}