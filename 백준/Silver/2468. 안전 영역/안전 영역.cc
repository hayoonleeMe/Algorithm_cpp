#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, t, ret = 1, mx_h;
int board[104][104];
bool visited[104][104];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (board[ny][nx] - t <= 0 || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			mx_h = max(mx_h, board[i][j]);
		}

	for (t = 1; t <= mx_h; ++t) {
		int cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] - t > 0 && !visited[i][j]) {
					dfs(i, j);
					++cnt;
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret;
}