#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;

int N, E, V1, V2;
vector<pair<int, int>> adj[805];
int d[805];

long long solve(int st, int en)
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

	cin >> N >> E;
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	cin >> V1 >> V2;

	long long ans1 = solve(1, V1) + solve(V1, V2) + solve(V2, N);
	long long ans2 = solve(1, V2) + solve(V2, V1) + solve(V1, N);
	long long ans = min(ans1, ans2);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}