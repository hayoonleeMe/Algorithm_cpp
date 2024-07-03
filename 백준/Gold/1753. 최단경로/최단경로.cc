#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int V, E, K;
// 비용, 간선번호
vector<pair<int, int>> adj[20005];
int d[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> V >> E >> K;
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	fill(d, d + V + 1, INF);
	d[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty())
	{
		const pair<int, int> cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.X)
			continue;

		for (const pair<int, int>& nxt : adj[cur.Y])
		{
			if (d[nxt.Y] <= d[cur.Y] + nxt.X)
				continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}

	for (int i = 1; i <= V; ++i)
		if (d[i] != INF)
			cout << d[i] << '\n';
		else
			cout << "INF\n";
}