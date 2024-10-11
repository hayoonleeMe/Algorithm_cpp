#include <bits/stdc++.h>
using namespace std;

int n, ret;
int board[23][23];

void rotate(int b[23][23]) {
	int temp[23][23] = { 0 };
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[i][j] = b[n - j - 1][i];
	memcpy(b, temp, sizeof(temp));
}

void solve(int b[23][23]) {
	int temp[23][23] = { 0 };
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			if (b[i][j] == 0) continue;
			if (temp[i][cur] == 0) {
				temp[i][cur] = b[i][j];
			} else if (temp[i][cur] == b[i][j]) {
				temp[i][cur] *= 2;
				++cur;
			} else {
				++cur;
				temp[i][cur] = b[i][j];
			}
		}
	}
	memcpy(b, temp, sizeof(temp));
}

void go(int cnt, int b[23][23]) {
	if (cnt == 5) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ret = max(ret, b[i][j]);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int temp[23][23] = { 0 };
		memcpy(temp, b, sizeof(temp));
		solve(temp);
		go(cnt + 1, temp);
		rotate(b);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	go(0, board);
	cout << ret;
}