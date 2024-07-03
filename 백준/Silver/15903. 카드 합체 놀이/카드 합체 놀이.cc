#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		pq.push(t);
	}

	while (M--)
	{
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		pq.push(a + b);
		pq.push(a + b);
	}
	
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}