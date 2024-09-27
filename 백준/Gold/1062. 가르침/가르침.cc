#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string s;
int word[52];
string alpha = "bdefghjklmopqrsuvwxyz";

void go(int start, int num, int b) {
	if (num == k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((b & word[i]) == word[i])
				++cnt;
		}
		ret = max(ret, cnt);
		return;
	}

	for (int i = start + 1; i < alpha.size(); ++i) {
		go(i, num + 1, b | (1 << (alpha[i] - 'a')));
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
		for (char c : s)
			word[i] |= (1 << (c - 'a'));
	}
	int b = (1 << ('a' - 'a')) | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'));
	go(-1, 0, b);
	cout << ret;
}