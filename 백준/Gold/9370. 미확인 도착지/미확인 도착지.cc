#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int T, n, m, t, s, g, h, a, b, d;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		vector<pair<int, int>> adj[2003];
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			d *= 2;
			if ((a == g && b == h) || (b == g && a == h))
				d -= 1;
			adj[a].push_back({ b, d });
			adj[b].push_back({ a, d });
		}
		int target[103];
		for (int i = 0; i < t; ++i)
			cin >> target[i];
		sort(target, target + t);

		vector<int> dist(2003, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		dist[s] = 0;
		pq.push({ 0, s });
		while (pq.size()) {
			int here_cost = pq.top().first;
			int u = pq.top().second;
			pq.pop();

			if (dist[u] != here_cost) continue;

			for (pair<int, int>& p : adj[u]) {
				int v = p.first;
				int weight = p.second;
				int new_cost = here_cost + weight;
				if (new_cost < dist[v]) {
					dist[v] = new_cost;
					pq.push({ new_cost, v });
				}
			}
		}

		for (int i = 0; i < t; ++i)
			if (dist[target[i]] % 2 == 1) cout << target[i] << ' ';
		cout << '\n';
	}
}