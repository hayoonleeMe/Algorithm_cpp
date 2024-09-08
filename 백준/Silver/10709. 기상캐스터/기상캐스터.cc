#include <bits/stdc++.h>
using namespace std;

int h, w, y, x;
string board[104];
int visited[104][104];
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		fill(visited[i], visited[i] + w, -1);
		cin >> board[i];
		for (int j = 0; j < w; ++j) {
			if (board[i][j] == 'c') {
				visited[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		int nx = x + 1;
		if (nx >= w) continue;
		if (board[y][nx] != '.') continue;
		visited[y][nx] = visited[y][x] + 1;
		q.push({ y,nx });
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}