#include <bits/stdc++.h>
using namespace std;

const int MAX = 500'000;
int n, k, ret = 1;
int visited[2][MAX + 4];
bool flag;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	visited[0][n] = 1;
	q.push(n);
	while (q.size()) {
		k += ret;
		if (k > MAX) break;
		if (visited[ret % 2][k]) {
			cout << ret;
			return 0;
		}

		int cnt = q.size();
		while (cnt--) {
			int cur = q.front(); q.pop();
			for (int nxt : { cur - 1, cur + 1, 2 * cur}) {
				if (nxt < 0 || nxt > MAX) continue;
				if (visited[ret % 2][nxt]) continue;
				if (nxt == k) {
					cout << ret;
					return 0;
				}
				visited[ret % 2][nxt] = visited[(ret + 1) % 2][cur] + 1;
				q.push(nxt);
			}
		}

		++ret;
	}
	cout << -1;
}