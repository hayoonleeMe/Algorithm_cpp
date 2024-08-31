#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, y, x, visited[104][104];
string board[104];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });

	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] == '0' || visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cout << visited[n - 1][m - 1];
}