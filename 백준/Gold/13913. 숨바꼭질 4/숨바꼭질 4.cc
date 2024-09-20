#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int pre[100'004], visited[100'004];
vector<int> path;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	visited[n] = 1;
	q.push(n);
	pre[n] = n;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == k) break;
		for (int nxt : { cur - 1, cur + 1, cur * 2 }) {
			if (nxt < 0 || nxt > 100000) continue;
			if (visited[nxt]) continue;
			visited[nxt] = visited[cur] + 1;
			q.push(nxt);
			pre[nxt] = cur;
		}
	}

	int cur = k;
	while (cur != n) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	
	cout << visited[k] - 1 << '\n';
	for (int p : path)
		cout << p << ' ';
}