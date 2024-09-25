#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e6;
string coin[22];

void flipRow(int r, vector<string>& b) {
	for (int c = 0; c < n; ++c)
		b[r][c] = b[r][c] == 'H' ? 'T' : 'H';
}

void go(vector<string>& b) {
	int cnt = 0;
	for (int c = 0; c < n; ++c) {
		int t = 0;
		for (int r = 0; r < n; ++r) {
			if (b[r][c] == 'T') ++t;
		}
		if (t > n / 2) t = n - t;
		cnt += t;
	}
	ret = min(ret, cnt);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	for (int i = 0; i < (1 << n); ++i) {
		vector<string> b(coin, coin + n);
		for (int j = 0; j < n; ++j)
			if (i & (1 << j)) flipRow(j, b);
		go(b);
	}
	cout << ret;
}