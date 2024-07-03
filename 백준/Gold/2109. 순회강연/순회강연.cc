#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ls[10005];
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int p, d;
		cin >> p >> d;
		ls[d].push_back(p);
	}

	int ans = 0;
	for (int i = 10000; i >= 1; --i)
	{
		for (int p : ls[i])
			pq.push(p);

		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}