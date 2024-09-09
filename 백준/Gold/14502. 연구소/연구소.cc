#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, ret, board[10][10];
bool visited[10][10];
vector<pair<int, int>> virus;

void dfs(int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (board[ny][nx] != 0 || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}

	for (int i = 0; i < n * m; ++i) {
		if (board[i / m][i % m] != 0) continue;
		for (int j = i + 1; j < n * m; ++j) {
			if (board[j / m][j % m] != 0) continue;
			for (int k = j + 1; k < n * m; ++k) {
				if (board[k / m][k % m] != 0) continue;

				for (int y = 0; y < n; ++y)
					fill(visited[y], visited[y] + m, 0);
				visited[i / m][i % m] = 1;
				visited[j / m][j % m] = 1;
				visited[k / m][k % m] = 1;

				for (auto vir : virus)
					dfs(vir.first, vir.second);

				int cnt = 0;
				for (int y = 0; y < n; ++y) {
					for (int x = 0; x < m; ++x) {
						if (board[y][x] == 0 && visited[y][x] == 0) ++cnt;	// 빈칸 & 바이러스가 방문X
					}
				}
				ret = max(ret, cnt);
			}
		}
	}
	cout << ret;
}