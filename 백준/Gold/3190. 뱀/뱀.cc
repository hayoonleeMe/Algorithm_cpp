#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };
int n, k, l, ret, a, b, dir;
char c;
int v[103][103]; // 1 : apple, 2 : D, 3 : L
queue<pair<int, char>> q;
deque<pair<int, int>> snake;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		v[a][b] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; ++i) {
		cin >> b >> c;
		q.push({ b, c });
	}
	snake.push_back({ 1,1 });
	while (1) {
		++ret;
		int ny = snake.front().first + dy[dir];
		int nx = snake.front().second + dx[dir];
		snake.push_front({ ny, nx });
		bool flag = 0;
		for (int i = 1; i < snake.size(); ++i) {
			// 머리가 몸이랑 박음
			if (snake[i].first == ny && snake[i].second == nx) {
				flag = 1;
				break;
			}
		}
		if (ny <= 0 || ny > n || nx <= 0 || nx > n || flag) break;
		// apple 
		if (v[ny][nx] == 1) v[ny][nx] = 0;
		else snake.pop_back();
		// 머리 방향 변경
		if (q.size() && ret == q.front().first) {
			v[ny][nx] = (q.front().second == 'D') ? 2 : 3;
			q.pop();
			if (v[ny][nx] == 2) dir = (dir + 1) % 4;
			else if (v[ny][nx] == 3) dir = (dir + 3) % 4;
		}
	}
	cout << ret;
}