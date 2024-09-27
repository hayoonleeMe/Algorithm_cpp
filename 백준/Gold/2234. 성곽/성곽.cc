#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };
int n, m, retCnt, retSize, retMaxSize;
int board[53][53];
bool visited[53][53];
pair<int, int> rooms[53][53];	// room id, size

void dfs(int y, int x, vector<pair<int, int>>& a) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (board[y][x] & (1 << dir)) continue;
		visited[ny][nx] = 1;
		a.push_back({ ny,nx });
		dfs(ny, nx, a);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j]) continue;
			++retCnt;
			visited[i][j] = 1;
			vector<pair<int, int>> v;
			v.push_back({ i,j });
			dfs(i, j, v);
			for (auto cur : v)
				rooms[cur.first][cur.second] = { r, v.size() };
			++r;
			retSize = max(retSize, (int)v.size());
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (!(board[i][j] & (1 << dir))) continue;
				if (rooms[i][j].first == rooms[ny][nx].first) continue;
				retMaxSize = max(retMaxSize, rooms[i][j].second + rooms[ny][nx].second);
			}
		}
	}
	cout << retCnt << '\n' << retSize << '\n' << retMaxSize;
}