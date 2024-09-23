#include <bits/stdc++.h>
using namespace std;

int n, m, h, a, b;
bool la[32][12];

bool solve(int st_n) {
	int y = 0, x = st_n;
	bool prev_horizontal = 0;
	while (y < h) {
		if (!prev_horizontal) {
			if (x + 1 < n && la[y][x]) {
				++x;
				prev_horizontal = 1;
				continue;
			}
			else if (x - 1 >= 0 && la[y][x - 1]) {
				--x;
				prev_horizontal = 1;
				continue;
			}
		}
		++y;
		prev_horizontal = 0;
	}
	return x == st_n;
}

void go(int y, int idx, int r) {
	if (idx == r) {
		for (int i = 0; i < n; ++i) {
			if (!solve(i)) return;
		}
		cout << r;
		exit(0);
		return;
	}

	for (int i = y; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			if (la[i][j]) continue;
			if (j - 1 >= 0 && la[i][j - 1]) continue;
			la[i][j] = 1;
			go(i, idx + 1, r);
			la[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		la[a - 1][b - 1] = 1;
	}
	for (int i = 0; i <= 3; ++i) {
		go(0, 0, i);
	}
	cout << -1;
}