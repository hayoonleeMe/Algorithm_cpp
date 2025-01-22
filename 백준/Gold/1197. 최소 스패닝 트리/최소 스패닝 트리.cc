#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, c;
vector<pair<int, int>> adj[10003];	// from = weight, to
bool visited[10003];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	visited[1] = 1;
	for (auto& p : adj[1])
		pq.push(p);
	while (ans.size() < v - 1) {
		tie(c, b) = pq.top();
		pq.pop();
		if (visited[b]) continue;
		visited[b] = 1;
		ans.push_back(c);
		for (auto& p : adj[b]) {
			if (!visited[p.second])
				pq.push(p);
		}
	}
	cout << accumulate(ans.begin(), ans.end(), 0);
}