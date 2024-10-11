#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, t, ret;
vector<vector<pair<int, int>>> board(20, vector<pair<int, int>>(20, {0,0}));

void move(int i, int j, int dir, int cnt) {
	if (board[i][j].first == 0) return;
	int ny, nx;
	while (1) {
		ny = i + dy[dir];
		nx = j + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
		if (board[ny][nx].first != 0) {
			if (board[ny][nx].first == board[i][j].first && board[ny][nx].second < cnt) {
				board[ny][nx].first *= 2;
				board[ny][nx].second = cnt;
				board[i][j].first = board[i][j].second = 0;
			}
			break;
		}
		swap(board[i][j], board[ny][nx]);
		i = ny;
		j = nx;
	}
}

void solve(int dir, int cnt, vector<vector<pair<int,int>>>& b) {
	switch (dir) {
	case 0:
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
				move(i, j, dir, cnt);
			}
		}
		break;
	case 1:
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				move(i, j, dir, cnt);
			}
		}
		break;
	case 2:
		for (int j = 0; j < n; ++j) {
			for (int i = n - 1; i >= 0; --i) {
				move(i, j, dir, cnt);
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				move(i, j, dir, cnt);
			}
		}
		break;
	}
}

void go(int cnt, vector<vector<pair<int,int>>>& b) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret = max(ret, board[i][j].first);
	if (cnt == 5) return;
	vector<vector<pair<int,int>>> temp(b.begin(), b.end());
	for (int dir = 0; dir < 4; ++dir) {
		solve(dir, cnt + 1, b);
		go(cnt + 1, b);
		b = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j].first;
	go(0, board);
	cout << ret;
}