#include <bits/stdc++.h>
using namespace std;

int t, k, n, d, ret;
string s;
vector<int> to[1003];

void go(int n, int d) {
	if (d > 0) rotate(to[n].rbegin(), to[n].rbegin() + 1, to[n].rend());
	else rotate(to[n].begin(), to[n].begin() + 1, to[n].end());
}

int findR(int n) {
	for (int i = n; i <= t; ++i) {
		if (i + 1 > t || to[i][2] == to[i+1][6]) return i;
	}
	return n;
}

int findL(int n) {
	for (int i = n; i >= 1; --i) {
		if (i - 1 < 1 || to[i][6] == to[i - 1][2]) return i;
	}
	return n;
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
		cin >> n >> d;
		int r = findR(n);
		int l = findL(n);
		int dir = d;
		for (int j = n; j <= r; ++j) {
			go(j, dir);
			dir = dir == 1 ? -1 : 1;
		}
		dir = d == 1 ? -1 : 1;
		for (int j = n - 1; j >= l; --j) {
			go(j, dir);
			dir = dir == 1 ? -1 : 1;
		}
	}
	for (int i = 1; i <= t; ++i)
		if (to[i][0] == 1) ++ret;
	cout << ret;
}