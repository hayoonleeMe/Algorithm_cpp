#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string s, word[52];
string alpha = "bdefghjklmopqrsuvwxyz";

void go(int start, int num, int b) {
	if (num == k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = 1;
			for (char c : word[i]) {
				int idx = (int)(c - 'a');
				if (!(b & (1 << idx))) {
					flag = 0;
					break;
				}
			}
			if (flag) ++cnt;
		}
		ret = max(ret, cnt);
		return;
	}

	for (int i = start + 1; i < alpha.size(); ++i) {
		go(i, num + 1, b | (1 << (int)(alpha[i] - 'a')));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		word[i] = s.substr(4, s.size() - 8);
	}
	int b = (1 << (int)('a' - 'a')) | (1 << (int)('c' - 'a')) | (1 << (int)('i' - 'a')) | (1 << (int)('n' - 'a')) | (1 << (int)('t' - 'a'));
	go(-1, 0, b);
	cout << ret;
}