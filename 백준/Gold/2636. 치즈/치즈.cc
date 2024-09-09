#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, ret, board[103][103];
bool visited[103][103];

void melt(int y, int x, vector<pair<int,int>>& cache) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (board[ny][nx] == 1) {
			visited[ny][nx] = 1;
			cache.push_back({ ny,nx });
			continue;
		}
		visited[ny][nx] = 1;
		melt(ny, nx, cache);
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1) ++cnt;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	ret = count();
	int day = 1;
	for (;; ++day) {
		// melting
		vector<pair<int, int>> cache;
		visited[0][0] = 1;
		melt(0, 0, cache);
		for (auto p : cache) board[p.first][p.second] = 0;

		// 조각 개수
		fill(&visited[0][0], &visited[n][m], 0);
		int cnt = count();
		if (cnt == 0) break;
		else ret = cnt;
	}
	cout << day << '\n' << ret;
}