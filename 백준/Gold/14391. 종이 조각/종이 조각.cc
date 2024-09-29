#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string st;
int board[5][5];
bool visRow[5][5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> st;
		for (int j = 0; j < m; ++j) board[i][j] = (int)(st[j] - '0');
	}

	for (int i = 0; i < (1 << n * m); ++i) {
		memset(visRow, 0, sizeof(visRow));
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				if (i & (1 << (m * r + c))) visRow[r][c] = 1;
			}
		}
		int sum = 0;
		// row
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				if (visRow[r][c]) {
					string s = to_string(board[r][c]);
					for (int t = c + 1; t < m; ++t) {
						if (!visRow[r][t]) break;
						s += to_string(board[r][t]);
					}
					c += s.size();
					sum += stoi(s);
				}
			}
		}
		// col
		for (int c = 0; c < m; ++c) {
			for (int r = 0; r < n; ++r) {
				if (visRow[r][c]) continue;
				string s = to_string(board[r][c]);
				for (int t = r + 1; t < n; ++t) {
					if (visRow[t][c]) break;
					s += to_string(board[t][c]);
				}
				r += s.size();
				sum += stoi(s);
			}
		}
		if (ret < sum) {
			ret = max(ret, sum);
		}
	}
	cout << ret;
}