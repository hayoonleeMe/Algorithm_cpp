#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<pair<int, int>> v;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;

		bool find = false;
		for (auto& p : v)
		{
			if (p.first == n)
			{
				++p.second;
				find = true;
				break;
			}
		}
		if (!find)
			v.push_back({ n, 1 });
	}

	stable_sort(v.begin(), v.end(), cmp);
	for (auto p : v)
	{
		while (p.second--)
			cout << p.first << ' ';
	}
}