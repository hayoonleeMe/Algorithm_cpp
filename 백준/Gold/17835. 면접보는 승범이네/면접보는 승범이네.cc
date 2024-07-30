#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, K;
vector<pair<long long, int>> adj[100'002];
long long d[100'002];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		long long c;
		cin >> u >> v >> c;
		adj[v].push_back({ c, u }); // 역방향
	}
	fill(d, d + N + 1, LLONG_MAX);
	// 다익스트라 시작점을 모든 면접장 위치로 넣어줌
	for (int i = 0; i < K; ++i)
	{
		int t; cin >> t;
		d[t] = 0;
		pq.push({ d[t], t });
	}

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

	int ansIndex = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (d[ansIndex] < d[i])
			ansIndex = i;
	}
	cout << ansIndex << '\n' << d[ansIndex];
}