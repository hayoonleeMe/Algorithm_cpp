#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };
int n, m, k, ret = 987654321, a, b, c;
int board[53][53], temp[53][53];
vector<tuple<int,int,int>> rot;
vector<int> idx;

void solve(int r, int c, int s, int b[53][53]) {
	vector<tuple<int, int, int>> v;
	int sy = r - s, sx = c - s;
	int dir = 0;
	while (1) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny < r - s || ny > r + s || nx < c - s || nx > c + s) {
			++dir;
			ny = sy + dy[dir];
			nx = sx + dx[dir];
		}
		v.push_back({ ny,nx, b[sy][sx] });
		sy = ny;
		sx = nx;
		if (sy == r - s && sx == c - s) break;
	}
	for (auto t : v)
		b[get<0>(t)][get<1>(t)] = get<2>(t);
	if (s - 1 > 0) solve(r, c, s - 1, b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c;
		rot.push_back({ a,b,c });
		idx.push_back(i);
	}
	do {
		memcpy(temp, board, sizeof(board));
		for (int i : idx)
			solve(get<0>(rot[i]), get<1>(rot[i]), get<2>(rot[i]), temp);
		for (int i = 1; i <= n; ++i)
			ret = min(ret, accumulate(temp[i] + 1, temp[i] + m + 1, 0));
	} while (next_permutation(idx.begin(), idx.end()));
	cout << ret;
}