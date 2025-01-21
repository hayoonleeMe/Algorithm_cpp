#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1, 0 };
const int dx[] = { 0, 1 };
const int MOD = 1000007;
int n, m, c, a, b;
int dp[53][53][53][53];
int v[53][53];

int go(int y, int x, int cnt, int prev) {
	if (cnt < 0) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && v[y][x] == 0) return 1;
		if (cnt == 1 && v[y][x] > prev) return 1;
		return 0;
	}
	int& ret = dp[y][x][cnt][prev];
	if (ret != -1) return ret;
	ret = 0;
	for (int dir = 0; dir < 2; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny > n || nx > m) continue;
		if (v[y][x] && v[y][x] > prev) {
			ret = (ret + go(ny, nx, cnt - 1, v[y][x])) % MOD;
		}
		if (v[y][x] == 0) {
			ret = (ret + go(ny, nx, cnt, prev)) % MOD;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; ++i) {
		cin >> a >> b;
		v[a][b] = i;
	}
	for (int i = 0; i <= c; ++i)
		cout << go(1, 1, i, 0) << ' ';
}