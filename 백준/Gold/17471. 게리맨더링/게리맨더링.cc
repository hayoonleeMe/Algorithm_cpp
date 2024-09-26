#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
int n, c, t, total, ret = INF;
int a[12];
int visited[12];
vector<int> adj[12];

int bfs(int team) {
	int cnt = 0, sum = 0;
	vector<int> tv(visited, visited + n + 1);
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (tv[i] != team) continue;
		++cnt;
		tv[i] = 3 * team;
		q.push(i);
		while (q.size()) {
			int cur = q.front(); q.pop();
			sum += a[cur];
			for (int nxt : adj[cur]) {
				if (tv[nxt] != team) continue;
				tv[nxt] = 3 * team;
				q.push(nxt);
			}
		}
	}
	if (cnt == 1) return sum;
	else return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		total += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> t;
			adj[i].push_back(t);
		}
	}

	for (int i = 1; i < (1 << n) - 1; ++i) {
		memset(visited, 0, sizeof(visited));
		for (int j = 1; j <= n; ++j) {
			if (i & (1 << j)) visited[j] = 1;
			else visited[j] = 2;
		}
		int t1 = bfs(1);
		int t2 = bfs(2);
		if (t1 > 0 && t2 > 0) ret = min(ret, abs(t1 - t2));
	}

	if (ret == INF) ret = -1;
	cout << ret;
}