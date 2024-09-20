#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100'004], cnt[100'004];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	visited[n] = 1;
	cnt[n] = 1;
	q.push(n);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100'000) continue;
			if (visited[nxt] == 0) {
				visited[nxt] = visited[cur] + 1;
				cnt[nxt] += cnt[cur];
				q.push(nxt);
			} else if (visited[nxt] == visited[cur] + 1) {
				cnt[nxt] += cnt[cur];
			}
		}
	}
	cout << visited[k] - 1 << '\n' << cnt[k];
}