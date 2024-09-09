#include <bits/stdc++.h>
using namespace std;

int n, t, root, ret, parent[53];
vector<int> adj[53];

void dfs(int here) {
	if (adj[here].empty()) {
		++ret;
		return;
	}
	for (int c : adj[here]) 
		dfs(c);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> parent[i];
		if (parent[i] == -1) root = i;
		else adj[parent[i]].push_back(i);
	}

	cin >> t;
	if (t == root) {
		cout << 0;
		return 0;
	}
	else {
		auto findIt = find(adj[parent[t]].begin(), adj[parent[t]].end(), t);
		if (findIt != adj[parent[t]].end())
			adj[parent[t]].erase(findIt);
	}

	dfs(root);
	cout << ret;
}