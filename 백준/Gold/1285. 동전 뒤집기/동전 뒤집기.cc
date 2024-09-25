#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e6;
string s;
int coin[22];

void go(int here) {
	if (here == n) {
		int cnt = 0;
		for (int c = 0; c < n; ++c) {
			int t = 0;
			for (int r = 0; r < n; ++r) {
				if (coin[r] & (1 << c)) ++t;
			}
			cnt += min(t, n - t);
		}
		ret = min(ret, cnt);
		return;
	}
	go(here + 1);
	coin[here] = ~coin[here];
	go(here + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		int value = 1;
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'T') coin[i] |= value;
			value *= 2;
		}
	}
	go(0);
	cout << ret;
}