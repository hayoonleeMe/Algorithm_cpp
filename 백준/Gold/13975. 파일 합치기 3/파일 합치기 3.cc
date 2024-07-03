#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq{};

		int K;
		cin >> K;
		while (K--)
		{
			int x;
			cin >> x;
			pq.push(x);
		}

		long long ans = 0;
		while (pq.size() > 1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();

			pq.push(a + b);
			ans += a + b;
		}
		cout << ans << '\n';
	}
}