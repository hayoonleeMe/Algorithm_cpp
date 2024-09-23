#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int r, c, k, ret;
string board[7];
bool visited[7][7];

void go(int y, int x, int t) {
	if (y == 0 && x == c - 1) {
		if (t == k) ++ret;
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx] || board[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		go(ny, nx, t + 1);
		visited[ny][nx] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;
	for (int i = 0; i < r; ++i)
		cin >> board[i];
	visited[r - 1][0] = 1;
	go(r - 1, 0, 1);
	cout << ret;
}