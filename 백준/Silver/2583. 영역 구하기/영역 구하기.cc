#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, k, x, y;
vector<int> areas;
int board[103][103];
bool visited[103][103];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	int x1, x2, y1, y2;
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j) {
				board[i][j] = 1;
			}
		}
	}
	
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!board[i][j] && !visited[i][j]) {
				int area = 0;
				visited[i][j] = 1;
				q.push({ i,j });
				while (q.size()) {
					tie(y, x) = q.front(); q.pop();
					++area;
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						if (board[ny][nx] || visited[ny][nx]) continue;
						visited[ny][nx] = 1;
						q.push({ ny,nx });
					}
				}
				areas.push_back(area);
			}
		}
	}
	sort(areas.begin(), areas.end());
	cout << areas.size() << '\n';
	for (int a : areas)
		cout << a << ' ';
}