#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;

int N, M, x;
vector<pair<int, int>> adj[1005];
int d[1005];

int solve(int st, int en)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	fill(d, d + N + 1, INF);
	d[st] = 0;
	pq.push({ d[st], st });

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
	return d[en];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> x;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	int max_time = -1;
	for (int i = 1; i <= N; ++i)
	{
		int time = solve(i, x) + solve(x, i);
		max_time = max(max_time, time);
	}
	cout << max_time;
}