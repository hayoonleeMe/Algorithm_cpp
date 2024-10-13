#include <bits/stdc++.h>
using namespace std;

struct shark {
	int s;	// 속력
	int d;	// 1:up 2:down 3:right 4:left
	int z;	// 크기
};

int r, c, m, a, b, s, d, z, ret, cur;
shark board[103][103], temp[103][103];

void moveH(shark s, int i, int j) {
	if (s.s > 0) {
		if (s.d == 4 && s.s < j - 1) j -= s.s;
		else {
			int l = s.s;
			if (s.d == 3) l += j - 1;
			else l -= j - 1;
			if (l > 0) s.d = 3;
			int q = l / (c - 1);
			int re = l % (c - 1);
			if (q % 2 == 0) {
				j = 1 + re;
				if (re == 0) s.d = 4;
			} else {
				j = c - re;
				if (re > 0) s.d = 4;
			}
		}
	}
	if (temp[i][j].z == 0) temp[i][j] = s;
	else if (temp[i][j].z < s.z) temp[i][j] = s;
}

void moveV(shark s, int i, int j) {
	if (s.s > 0) {
		if (s.d == 1 && s.s < i - 1) i -= s.s;
		else {
			int l = s.s;
			if (s.d == 2) l += i - 1;
			else l -= i - 1;
			if (l > 0) s.d = 2;
			int q = l / (r - 1);
			int re = l % (r - 1);
			if (q % 2 == 0) {
				i = 1 + re;
				if (re == 0) s.d = 1;
			} else {
				i = r - re;
				if (re > 0) s.d = 1;
			}
		}
	}
	if (temp[i][j].z == 0) temp[i][j] = s;
	else if (temp[i][j].z < s.z) temp[i][j] = s;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> s >> d >> z;
		board[a][b] = { s,d,z };
	}
	while (cur < c) {
		++cur;
		// catch
		for (int i = 1; i <= r; ++i) {
			if (board[i][cur].z != 0) {
				ret += board[i][cur].z;
				board[i][cur] = { 0,0,0 };
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if (board[i][j].z == 0) continue;
				if (board[i][j].d < 3) moveV(board[i][j], i, j);
				else moveH(board[i][j], i, j);
			}
		}
		memcpy(board, temp, sizeof(temp));
	}
	cout << ret;
}