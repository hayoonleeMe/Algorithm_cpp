#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };
const int R = 100;
const int C = 100;
int n, x, y, d, g, ret;
bool board[R + 3][C + 3];
vector<int> dir;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> d >> g;

		dir.clear();
		board[y][x] = 1;
		y += dy[d]; x += dx[d];
		board[y][x] = 1;
		dir.push_back(d);
		for (int j = 1; j <= g; ++j) {
			for (int nd : dir) s.push(nd);
			while (s.size()) {
				int nd = s.top(); s.pop();
				nd = (nd + 1) % 4;
				y += dy[nd];
				x += dx[nd];
				board[y][x] = 1;
				dir.push_back(nd);
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ++ret;
		}
	}
	cout << ret;
}