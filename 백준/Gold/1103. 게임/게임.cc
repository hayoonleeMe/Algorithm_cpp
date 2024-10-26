#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;
string board[53];
int dp[53][53];
bool visited[53][53];

int go(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return INF;
	if (board[y][x] == 'H') return INF;
	if (visited[y][x]) {
		cout << -1;
		exit(0);
	}
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	visited[y][x] = 1;
	int len = (int)(board[y][x] - '0');
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir] * len;
		int nx = x + dx[dir] * len;
		ret = max(ret, go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> board[i];
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) + 1;
}