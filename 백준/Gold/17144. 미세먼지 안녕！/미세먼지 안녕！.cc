#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int r, c, t, ret;
int a[53][53], temp[53][53];
pair<int, int> top, bot;

void topac() {
	for (int i = top.first; i - 1 >= 0; --i) {
		if (a[i][0] == -1) a[i - 1][0] = 0;
		else  swap(a[i][0], a[i - 1][0]);
	}
	for (int j = 0; j + 1 < c; ++j) {
		swap(a[0][j], a[0][j + 1]);
	}
	for (int i = 0; i + 1 <= top.first; ++i) {
		swap(a[i][c - 1], a[i + 1][c - 1]);
	}
	for (int j = c - 1; j - 1 > 0; --j) {
		swap(a[top.first][j], a[top.first][j - 1]);
	}
}

void botac() {
	for (int i = bot.first; i + 1 < r; ++i) {
		if (a[i][0] == -1) a[i + 1][0] = 0;
		else swap(a[i][0], a[i + 1][0]);
	}
	for (int j = 0; j + 1 < c; ++j) {
		swap(a[r - 1][j], a[r - 1][j + 1]);
	}
	for (int i = r - 1; i - 1 >= bot.first; --i) {
		swap(a[i][c - 1], a[i - 1][c - 1]);
	}
	for (int j = c - 1; j - 1 > 0; --j) {
		swap(a[bot.first][j], a[bot.first][j - 1]);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				if (top.first == 0) top = { i,j };
				else bot = { i,j };
			}
		}
	}
	while (t--) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int s = a[i][j] / 5;
				if (a[i][j] <= 0 || s <= 0) continue;
				int cnt = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
					if (a[ny][nx] == -1) continue;
					++cnt;
					temp[ny][nx] += s;
				}
				temp[i][j] -= cnt * s;
			}
		}
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (temp[i][j] != 0) {
					a[i][j] += temp[i][j];
					temp[i][j] = 0;
				}
		topac();
		botac();
	}
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (a[i][j] > 0) ret += a[i][j];
	cout << ret;
}