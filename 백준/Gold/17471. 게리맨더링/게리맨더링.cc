#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, a[12], t, c, ret = INF;
int visited[12], comp[12];
vector<int> adj[12];

pair<int, int> dfs(int here, int team) {
	pair<int, int> ret = { 1, a[here] };
	visited[here] = 1;
	for (int nxt : adj[here]) {
		if (visited[nxt] || comp[nxt] != team) continue;
		pair<int, int> temp = dfs(nxt, team);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> t;
			adj[i].push_back(t);
			adj[t].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; ++i) {
		memset(visited, 0, sizeof(visited));
		memset(comp, 0, sizeof(comp));
		int idx0 = -1, idx1 = -1;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				comp[j + 1] = 1;
				idx1 = j + 1;
			} else idx0 = j + 1;
		}
		pair<int, int> ret0 = dfs(idx0, 0);
		pair<int, int> ret1 = dfs(idx1, 1);
		if (ret0.first + ret1.first == n)
			ret = min(ret, abs(ret0.second - ret1.second));
	}
	if (ret == INF) ret = -1;
	cout << ret;
}