#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, st, en;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1005];
int d[1005];
int pre[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	cin >> st >> en;

	fill(d, d + n + 1, INF);
	d[st] = 0;
	pre[st] = 0;
	pq.push({ d[st], st });
	
	while (!pq.empty())
	{
		const pair<int, int> cur = pq.top();
		pq.pop();

		if (cur.X != d[cur.Y])
			continue;

		for (const pair<int, int>& nxt : adj[cur.Y])
		{
			if (d[nxt.Y] <= d[cur.Y] + nxt.X)
				continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pre[nxt.Y] = cur.Y;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	cout << d[en] << '\n';

	vector<int> route;
	int cur = en;
	while (cur != st)
	{
		route.push_back(cur);
		cur = pre[cur];
	}
	route.push_back(st);
	reverse(route.begin(), route.end());

	cout << route.size() << '\n';
	for (int r : route)
		cout << r << ' ';
}