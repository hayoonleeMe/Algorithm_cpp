#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, l, r, ret;
int board[53][53];
bool visited[53][53];

void dfs(int y, int x, int& sum, vector<pair<int, int>>& uni) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		const int gap = abs(board[y][x] - board[ny][nx]);
		if (l <= gap && gap <= r) {
			sum += board[ny][nx];
			visited[ny][nx] = 1;
			uni.push_back({ ny,nx });
			dfs(ny, nx, sum, uni);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	while (true) {
		memset(visited, 0, sizeof(visited));
		bool flag = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j]) continue;
				vector<pair<int, int>> uni;
				visited[i][j] = 1;
				uni.push_back({ i,j });
				int sum = board[i][j];
				dfs(i, j, sum, uni);
				if (uni.size() == 1) continue;
				flag = 1;
				sum /= uni.size();
				for (auto p : uni) {
					board[p.first][p.second] = sum;
				}
			}
		}
		if (!flag) break;
		++ret;
	}
	cout << ret;
}