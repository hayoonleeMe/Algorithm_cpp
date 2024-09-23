#include <bits/stdc++.h>
using namespace std;

int n, board[12][12], ret = 1e6;
bool visited[12][12];

void go(int cnt, int sum) {
	if (cnt == 3) {
		ret = min(ret, sum);
		return;
	}

	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			if (visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = visited[i - 1][j] = visited[i + 1][j] = visited[i][j - 1] = visited[i][j + 1] = 1;
			int t = board[i][j] + board[i - 1][j] + board[i + 1][j] + board[i][j - 1] + board[i][j + 1];
			go(cnt + 1, sum + t);
			visited[i][j] = visited[i - 1][j] = visited[i + 1][j] = visited[i][j - 1] = visited[i][j + 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	go(0, 0);
	cout << ret;
}