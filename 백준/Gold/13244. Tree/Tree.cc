#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
bool adj[1003][1003];
bool visited[1003];

void dfs(int here) {
	visited[here] = 1;
	for (int i = 1; i <= n; ++i) {
		if (adj[here][i] && !visited[i]) dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		int st = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				dfs(i);
				++cnt;
			}
		}
		if (m == n - 1 && cnt == 1) cout << "tree\n";
		else cout << "graph\n";
	}
}