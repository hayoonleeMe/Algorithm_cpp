#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
vector<tuple<string, int, int>> v;
unordered_map<string, int> m;
int ans;
int dur[100];

bool compare(const tuple<string, int, int>& a, const tuple<string, int, int>& b)
{
	return get<1>(a) < get<1>(b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		int w, d, p;
		cin >> s >> w >> d >> p;
		int nd = (w - 1) * 7 + d;
		v.push_back({ s, nd, p });
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; ++i)
	{
		string s;
		int p;
		cin >> s >> p;
		m[s] = p;
	}

	for (auto t : v)
	{
		int d = get<1>(t);
		int wp = get<2>(t);
		int rp = m[get<0>(t)];

		if (rp >= wp)
			++dur[d];
	}

	int dd = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (dur[i] > 0)
			++dd;
		else
		{
			ans = max(ans, dd);
			dd = 0;
		}
	}
	ans = max(ans, dd);
	cout << ans;
}