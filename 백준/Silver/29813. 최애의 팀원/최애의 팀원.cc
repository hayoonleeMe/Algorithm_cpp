#include <bits/stdc++.h>
using namespace std;

int N;
deque<pair<string, int>> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		int n;
		cin >> s >> n;
		dq.push_back({ s, n });
	}

	while (dq.size() > 1)
	{
		int cnt = (dq[0].second - 1) % (dq.size() - 1);
		rotate(dq.begin() + 1, dq.begin() + 1 + cnt, dq.end());
		dq.pop_front();
		dq.pop_front();
	}

	cout << dq[0].first;
}