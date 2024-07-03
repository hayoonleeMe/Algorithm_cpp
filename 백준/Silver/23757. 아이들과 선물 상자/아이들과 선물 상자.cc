#include <bits/stdc++.h>
using namespace std;

int N, M;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int c;
		cin >> c;
		pq.push(c);
	}

	for (int i = 0; i < M; ++i)
	{
		int w;
		cin >> w;

		int p = pq.top();
		if (w <= p)
		{
			pq.pop();
			if (p - w > 0)
				pq.push(p - w);
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}