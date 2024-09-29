#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string st;
int board[5][5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> st;
		for (int j = 0; j < m; ++j) board[i][j] = (int)(st[j] - '0');
	}

	for (int i = 0; i < (1 << n * m); ++i) {
		int sum = 0;
		// row
		for (int r = 0; r < n; ++r) {
			int cur = 0;
			for (int c = 0; c < m; ++c) {
				if (i & (1 << (r * m + c))) {
					cur = cur * 10 + board[r][c];
				} else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		// col
		for (int c = 0; c < m; ++c) {
			int cur = 0;
			for (int r = 0; r < n; ++r) {
				if ((i & (1 << (r * m + c))) == 0) {
					cur = cur * 10 + board[r][c];
				} else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ret = max(ret, sum);
	}
	cout << ret;
}