#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string alpha = "bdefghjklmopqrsuvwxyz";
string s, word[52];
bool b[26];

void go(int start, int num) {
	if (num == k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = 1;
			for (char c : word[i]) {
				if (!b[(int)(c - 'a')]) {
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
		int idx = (int)(alpha[i] - 'a');
		b[idx] = 1;
		go(i, num + 1);
		b[idx] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	b[(int)('a' - 'a')] = b[(int)('c' - 'a')] = b[(int)('i' - 'a')] = b[(int)('n' - 'a')] = b[(int)('t' - 'a')] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		word[i] = s.substr(4, s.size() - 8);
	}
	go(-1, 0);
	cout << ret;
}