#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, max_cnt = -1;
vector<int> adj[10003], v;
bool visited[10003];

int dfs(int here) {
	int ret = 1;
	for (int there : adj[here]) {
		if (!visited[there]) {
			visited[there] = 1;
			ret += dfs(there);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		fill(visited, visited + n + 1, 0);

		visited[i] = 1;
		int cnt = dfs(i);
		if (max_cnt < cnt) {
			max_cnt = cnt;
			v.clear();
			v.push_back(i);
		} else if (max_cnt == cnt) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (int c : v)
		cout << c << ' ';
}