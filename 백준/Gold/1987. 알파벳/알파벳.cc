#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int r, c, ret;
string board[22];
bool visited[22][22];
map<char, int> mp;

void go(int y, int x, int num) {
	ret = max(ret, num);

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx]) continue;
		if (mp[board[ny][nx]]) continue;
		visited[ny][nx] = 1;
		mp[board[ny][nx]] = 1;
		go(ny, nx, num + 1);
		visited[ny][nx] = 0;
		mp[board[ny][nx]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) 
		cin >> board[i];

	mp[board[0][0]] = 1;
	visited[0][0] = 1;
	go(0, 0, 1);
	cout << ret;
}