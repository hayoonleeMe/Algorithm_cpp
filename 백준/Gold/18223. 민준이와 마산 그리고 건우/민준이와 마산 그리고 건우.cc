#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int V, E, P;
vector<pair<int, int>> adj[5002];
int d[5002];
int pre[5002];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> V >> E >> P;
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	fill(d, d + V + 1, 0x7f7f7f7f);
	d[1] = 0;
	pq.push({ d[1], 1 });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X)
			continue;

		for (auto nxt : adj[cur.Y])
		{
			if (d[nxt.Y] < d[cur.Y] + nxt.X)
				continue;
			if (d[nxt.Y] == d[cur.Y] + nxt.X && cur.Y != P)
				continue;

			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
			pre[nxt.Y] = cur.Y;
		}
	}

	vector<int> path;
	int cur = V;
	while (cur != 1)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);

	if (find(path.begin(), path.end(), P) != path.end())
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
}