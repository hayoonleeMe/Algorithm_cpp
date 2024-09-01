#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int t, m, n, k, x, y, ret;
int board[55][55];
bool visited[55][55];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (board[ny][nx] == 0 || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		ret = 0;
		for (int i = 0; i < n; ++i) {
			memset(board[i], 0, sizeof(int) * m);
			memset(visited[i], 0, sizeof(int) * m);
		}
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] && !visited[i][j]) {
					dfs(i, j);
					++ret;
				}
			}
		}
		cout << ret << '\n';
	}
}