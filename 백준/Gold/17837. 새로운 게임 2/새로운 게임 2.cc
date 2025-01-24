#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 0, 0, -1, 1 };
const int dx[] = { 0, 1, -1, 0, 0 };
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

struct Pawn {
	int y, x, dir;

	void reverseDirection() {
		if (dir == 1) dir = 2;
		else if (dir == 2) dir = 1;
		else if (dir == 3) dir = 4;
		else if (dir == 4) dir = 3;
	}
};

int n, k, a, b, c, ans;
int board[14][14];
vector<Pawn*> v[14][14];
vector<Pawn*> pawns;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c;
		Pawn* pawn = new Pawn{ a, b, c };
		pawns.push_back(pawn);
		v[a][b].push_back(pawn);
	}

	while (1) {
		++ans;
		if (ans > 1000) {
			cout << -1;
			return 0;
		}

		for (int i = 0; i < k; ++i) {
			Pawn* pawn = pawns[i];
			int ny = pawn->y + dy[pawn->dir];
			int nx = pawn->x + dx[pawn->dir];
			if (ny < 1 || ny > n || nx < 1 || nx > n || board[ny][nx] == BLUE) {
				pawn->reverseDirection();
				ny = pawn->y + dy[pawn->dir];
				nx = pawn->x + dx[pawn->dir];
				if (ny < 1 || ny > n || nx < 1 || nx > n || board[ny][nx] == BLUE) continue;
			}

			auto it = find(v[pawn->y][pawn->x].begin(), v[pawn->y][pawn->x].end(), pawn);
			vector<Pawn*> temp(it, v[pawn->y][pawn->x].end());
			v[pawn->y][pawn->x].erase(it, v[pawn->y][pawn->x].end());
			for (Pawn* pawn : temp) {
				pawn->y = ny;
				pawn->x = nx;
			}
			if (board[ny][nx] == RED)
				reverse(temp.begin(), temp.end());
			move(temp.begin(), temp.end(), back_inserter(v[ny][nx]));

			if (v[ny][nx].size() >= 4) {
				cout << ans;
				return 0;
			}
		}
	}
}