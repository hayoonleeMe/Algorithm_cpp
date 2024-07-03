#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;

int n, m, s, t;
vector<pair<int, int>> adj[5005];
int d[5005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	cin >> s >> t;

	fill(d, d + n + 1, INF);
	d[s] = 0;
	pq.push({ d[s], s });
	
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

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

	cout << d[t];
}