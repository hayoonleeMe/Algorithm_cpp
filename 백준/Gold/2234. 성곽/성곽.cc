#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };
int n, m, retCnt, retSize, retMaxSize;
int board[53][53], visited[53][53], roomSize[2503];

int dfs(int y, int x) {
	int ret = 1;
	visited[y][x] = retCnt;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (board[y][x] & (1 << dir)) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j]) continue;
			++retCnt;
			roomSize[retCnt] = dfs(i, j);
			retSize = max(retSize, roomSize[retCnt]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (!(board[i][j] & (1 << dir))) continue;
				if (visited[i][j] == visited[ny][nx]) continue;
				retMaxSize = max(retMaxSize, roomSize[visited[i][j]] + roomSize[visited[ny][nx]]);
			}
		}
	}
	cout << retCnt << '\n' << retSize << '\n' << retMaxSize;
}