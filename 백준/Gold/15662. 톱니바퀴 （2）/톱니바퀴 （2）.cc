#include <bits/stdc++.h>
using namespace std;

int t, k, n, d, ret;
string s;
vector<int> to[1003], temp[1003];
bool visited[1003];

void go(int n, int d) {
	visited[n] = 1;
	if (d > 0) rotate(to[n].rbegin(), to[n].rbegin() + 1, to[n].rend());
	else rotate(to[n].begin(), to[n].begin() + 1, to[n].end());
	if (n + 1 <= t && !visited[n + 1] && temp[n][2] != temp[n + 1][6]) go(n + 1, (d == 1 ? -1 : 1));
	if (n - 1 >= 1 && !visited[n - 1] && temp[n][6] != temp[n - 1][2]) go(n - 1, (d == 1 ? -1 : 1));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> s;
		for (char c : s)
			to[i].push_back(c - '0');
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j <= t; ++j)
			temp[j] = to[j];
		memset(visited, 0, sizeof(visited));
		cin >> n >> d;
		go(n, d);
	}
	for (int i = 1; i <= t; ++i)
		if (to[i][0] == 1) ++ret;
	cout << ret;
}