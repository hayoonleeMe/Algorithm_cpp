#include <bits/stdc++.h>
using namespace std;

int n, l, ret;
bool t;
int board[103][103];

bool checkRow(int r) {
	bool flag = 0;
	int h = board[r][0], cnt = 1;
	for (int c = 1; c < n; ++c) {
		if (h != board[r][c]) {
			if (flag) {
				if (cnt < l) return 0;
				flag = 0;
				cnt = 0;
			}

			if (abs(h - board[r][c]) > 1) return 0;
			if (h > board[r][c]) {
				flag = 1;
			}
			else if (h < board[r][c]) {
				if (cnt < l) return 0;
			}

			h = board[r][c];
			cnt = 1;
		} else {
			++cnt;
		}
		if (flag && cnt >= l) {
			flag = 0;
			cnt = 0;
		}
	}
	if (flag) {
		if (cnt < l) return 0;
		flag = 0;
		cnt = 0;
	}
	return 1;
}

bool checkCol(int c) {
	bool flag = 0;
	int h = board[0][c], cnt = 1;
	for (int r = 1; r < n; ++r) {
		if (h != board[r][c]) {
			if (flag) {
				if (cnt < l) return 0;
				flag = 0;
				cnt = 0;
			}

			if (abs(h - board[r][c]) > 1) return 0;
			if (h > board[r][c]) {
				flag = 1;
			}
			else if (h < board[r][c]) {
				if (cnt < l) return 0;
			}

			h = board[r][c];
			cnt = 1;
		}
		else {
			++cnt;
		}
		if (flag && cnt >= l) {
			flag = 0;
			cnt = 0;
		}
	}
	if (flag) {
		if (cnt < l) return 0;
		flag = 0;
		cnt = 0;
	}
	return 1;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	for (int r = 0; r < n; ++r) {
		ret += checkRow(r);
	}
	for (int c = 0; c < n; ++c) {
		ret += checkCol(c);
	}

	cout << ret;
}