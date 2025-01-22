#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int n, m, k, a, b, c, ans;
int A[12][12];
int board[12][12];
vector<int> trees[12][12];

void SpringAndSummer(int i, int j) {
	vector<int> dead;
	// 봄
	sort(trees[i][j].begin(), trees[i][j].end());
	for (int& age : trees[i][j]) {
		if (board[i][j] >= age) {
			board[i][j] -= age;
			age += 1;
		} else {
			dead.push_back(age);
		}
	}
	trees[i][j].resize(trees[i][j].size() - dead.size());

	// 여름
	for (int age : dead) {
		board[i][j] += age / 2;
	}
}

void Fall(int i, int j) {
	for (int age : trees[i][j]) {
		if (age % 5 == 0) {
			for (int dir = 0; dir < 8; ++dir) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
				trees[ny][nx].push_back(1);
			}
		}
	}
}

void Winter() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			board[i][j] += A[i][j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> A[i][j];
			board[i][j] = 5;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		trees[a][b].push_back(c);
	}

	for (int year = 1; year <= k; ++year) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (trees[i][j].empty()) continue;
				SpringAndSummer(i, j);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (trees[i][j].empty()) continue;
				Fall(i, j);
			}
		}
		Winter();
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans += trees[i][j].size();
	cout << ans;
}