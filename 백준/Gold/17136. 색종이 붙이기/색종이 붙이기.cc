#include <bits/stdc++.h>
using namespace std;

int LEN[] = { 1, 3, 4, 5, 6, 7 };
int board[12][12];
int lenCnt[6] = { 0, };
int ans = 1234567890;

void go(int y, int x) {
	if (y == 9 && x == 10) {
		int cnt = 0;
		bool bCorrect = true;
		for (int len = 1; len <= 5; ++len) {
			if (lenCnt[len] > 5) {
				bCorrect = false;
				return;
			}
			cnt += lenCnt[len];
		}
		ans = min(ans, cnt);
		return;
	}

	if (x == 10) {
		++y;
		x = 0;
	}

	if (board[y][x] != 1) {
		go(y, x + 1);
		return;
	}

	for (int len = 1; len <= 5; ++len) {
		if (y + len > 10 || x + len > 10) return;
		for (int ny = y; ny < y + len; ++ny) {
			for (int nx = x; nx < x + len; ++nx)
				if (board[ny][nx] != 1) return;
		}
		if (lenCnt[len] + 1 > 5) continue;

		for (int ny = y; ny < y + len; ++ny)
			for (int nx = x; nx < x + len; ++nx)
				board[ny][nx] = LEN[len];
		lenCnt[len]++;
		go(y, x + len);
		lenCnt[len]--;
		for (int ny = y; ny < y + len; ++ny)
			for (int nx = x; nx < x + len; ++nx)
				board[ny][nx] = LEN[0];
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> board[i][j];
	go(0, 0);
	if (ans == 1234567890) ans = -1;
	cout << ans;
}