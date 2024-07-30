#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
vector<pair<int, int>> adj[50'002];

int d[50'002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	fill(d, d + N + 1, 0x7f7f7f7f);

	d[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X)
			continue;

		for (auto nxt : adj[cur.Y])
		{
			if (d[nxt.Y] <= d[cur.Y] + nxt.X)
				continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	cout << d[N];
}