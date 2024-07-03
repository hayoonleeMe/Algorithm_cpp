#include <bits/stdc++.h>
using namespace std;

int N, K;
priority_queue<int, vector<int>> pq[13];
int a[13];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		pq[a].push(b);
	}

	for (int i = 1; i <= K; ++i)
	{
		for (int p = 1; p <= 11; ++p)
		{
			if (pq[p].empty())
				continue;

			if (a[p] < pq[p].top())
			{
				int t = a[p];
				a[p] = pq[p].top();
				pq[p].pop();
				pq[p].push(t);
			}
		}

		for (int p = 1; p <= 11; ++p)
			a[p] = max(0, a[p] - 1);

		for (int p = 1; p <= 11; ++p)
		{
			if (pq[p].empty())
				continue;

			if (a[p] < pq[p].top())
			{
				int t = a[p];
				a[p] = pq[p].top();
				pq[p].pop();
				pq[p].push(t);
			}
		}
	}

	int ans = 0;
	for (int p = 1; p <= 11; ++p)
		ans += a[p];
	cout << ans;
}