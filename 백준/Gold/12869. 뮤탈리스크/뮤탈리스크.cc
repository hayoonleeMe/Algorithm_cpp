#include <bits/stdc++.h>
using namespace std;

int n, v[3], a, b, c;
int visited[63][63][63];
int damage[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3}
};

struct A {
	int a, b, c;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	queue<A> q;
	visited[v[0]][v[1]][v[2]] = 1;
	q.push({ v[0], v[1], v[2] });
	while (q.size()) {
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();

		if (visited[0][0][0]) break;

		for (int i = 0; i < 6; ++i) {
			int na = max(0, a - damage[i][0]);
			int nb = max(0, b - damage[i][1]);
			int nc = max(0, c - damage[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}
	cout << visited[0][0][0] - 1;
}