#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, y, x, visited[53][53], ret;
string board[53];
vector<pair<int, int>> land;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'L') land.push_back({ i,j });
		}
	}

	for (auto L : land) {
		memset(visited, -1, sizeof(visited));

		queue<pair<int, int>> q;
		visited[L.first][L.second] = 0;
		q.push(L);

		while (q.size()) {
			tie(y, x) = q.front();
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx] >= 0 || board[ny][nx] != 'L') continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
				ret = max(ret, visited[ny][nx]);
			}
		}
	}
	cout << ret;
}