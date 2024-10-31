#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000007;
int n, m, c, ty, tx;
int board[53][53];
ll dp[53][53][53][53];

ll go(int y, int x, int cnt, int pre) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && board[y][x] == 0) return 1;
		if (cnt == 1 && board[y][x] > pre) return 1;
		return 0;
	}
	ll& ret = dp[y][x][cnt][pre];
	if (ret != -1) return ret;
	ret = 0;
	if (board[y][x] == 0)
		ret += (go(y + 1, x, cnt, pre) + go(y, x + 1, cnt, pre)) % MOD;
	if (board[y][x] > pre)
		ret += (go(y + 1, x, cnt - 1, board[y][x]) + go(y, x + 1, cnt - 1, board[y][x])) % MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> c;
	for (int i = 1; i <= c; ++i) {
		cin >> ty >> tx;
		board[ty][tx] = i;
	}
	for (int i = 0; i <= c; ++i) {
		memset(dp, -1, sizeof(dp));
		cout << go(1, 1, i, 0) << ' ';
	}
}