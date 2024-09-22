#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0,1,0,-1 };
int r, c, y, x, ret;
string board[1503];
bool v_wa[1503][1503], v_sw[1503][1503];
queue<pair<int, int>> wa, sw;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> board[i];
		for (int j = 0; j < c; ++j) {
			if (board[i][j] == 'L' && sw.empty()) {
				board[i][j] = '.';
				v_sw[i][j] = 1;
				sw.push({ i,j });
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (board[i][j] == '.' || board[i][j] == 'L') {
				v_wa[i][j] = 1;
				for (int dir = 0; dir < 4; ++dir) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
					if (board[ny][nx] == 'X') {
						wa.push({ i,j });
						break;
					}
				}
			}
		}
	}
	
	bool flag = 0;
	while (1) {
		// 백조 이동
		queue<pair<int, int>> temp;
		while (sw.size()) {
			tie(y, x) = sw.front(); sw.pop();
			if (board[y][x] == 'L') {
				flag = 1;
				break;
			}
			
			bool bPushed = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (v_sw[ny][nx]) continue;
				if (board[ny][nx] == 'X') {
					if (!bPushed) {
						bPushed = 1;
						temp.push({ y,x });
					}
				} else {
					v_sw[ny][nx] = 1;
					sw.push({ ny,nx });
				}
			}
		}
		if (flag) break;
		sw = temp;
		++ret;

		// 빙하녹음
		int cnt = wa.size();
		while (cnt--) {
			tie(y, x) = wa.front(); wa.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (v_wa[ny][nx]) continue;
				v_wa[ny][nx] = 1;
				if (board[ny][nx] == 'X') {
					board[ny][nx] = '.';
					wa.push({ ny,nx });
				}
			}
		}
	}
	cout << ret;
}