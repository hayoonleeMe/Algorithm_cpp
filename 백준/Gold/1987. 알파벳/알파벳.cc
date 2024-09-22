#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int r, c, ret;
string board[22];
bool alpha[30];

void go(int y, int x, int num) {
	ret = max(ret, num);

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (alpha[board[ny][nx] - 'A']) continue;
		alpha[board[ny][nx] - 'A'] = 1;
		go(ny, nx, num + 1);
		alpha[board[ny][nx] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) 
		cin >> board[i];

	alpha[board[0][0] - 'A'] = 1;
	go(0, 0, 1);
	cout << ret;
}