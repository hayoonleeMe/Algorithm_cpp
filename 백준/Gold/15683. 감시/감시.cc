#include <bits/stdc++.h>
using namespace std;

struct Cctv {
	int y;
	int x;
	vector<int> dir;
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, ret = 987654321;
int board[10][10], temp[10][10];
vector<Cctv> cctvs, b;

void dfs(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny < 0 || ny >= n || nx < 0 || nx >= m) return;
	if (temp[ny][nx] == 6) return;
	temp[ny][nx] = -1;
	dfs(ny, nx, dir);
}

void go() {
	if (b.size() == cctvs.size()) {
		memcpy(temp, board, sizeof(board));
		for (auto& cctv : b) {
			for (int d : cctv.dir) dfs(cctv.y, cctv.x, d);
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (temp[i][j] == 0)
					++cnt;
		ret = min(ret, cnt);
		return;
	}

	for (int d = 0; d < 4; ++d) {
		Cctv t = cctvs[b.size()];
		for (int& i : t.dir)
			i = (i + d) % 4;
		b.push_back(t);
		go();
		b.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			switch (board[i][j]) {
			case 1:
				cctvs.push_back({ i,j, { 1 } });
				break;
			case 2:
				cctvs.push_back({ i,j, { 1, 3 } });
				break;
			case 3:
				cctvs.push_back({ i,j, { 0, 1 } });
				break;
			case 4:
				cctvs.push_back({ i,j, { 0, 1, 3 } });
				break;
			case 5:
				cctvs.push_back({ i,j, { 0, 1, 2, 3 } });
				break;
			}
		}
	}
	go();
	cout << ret;
}