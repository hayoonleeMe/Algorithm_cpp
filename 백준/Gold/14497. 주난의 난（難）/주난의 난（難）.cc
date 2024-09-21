#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, x, y, ret;
bool visited[304][304];
string board[304];
pair<int, int> en;
queue<pair<int, int>> q;

void go(int y, int x) {
	visited[y][x] = 1;
	if (board[y][x] == '1') {
		board[y][x] = '0';
		q.push({ y,x });
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		go(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> x >> y;
	q.push({ x - 1, y - 1 });
	cin >> x >> y;
	en = { x - 1, y - 1 };
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	while (1) {
		++ret;

		int cnt = q.size();
		while (cnt--) {
			auto cur = q.front(); q.pop();
			go(cur.first, cur.second);
		}
		if (visited[en.first][en.second]) {
			cout << ret;
			return 0;
		}
	}
}