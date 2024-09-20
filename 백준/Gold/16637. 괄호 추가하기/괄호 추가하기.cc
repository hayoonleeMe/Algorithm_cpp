#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> num;
vector<char> oper;

int calc(char op, int a, int b) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void go(int here, int sum) {
	if (here == num.size() - 1) {
		ret = max(ret, sum);
		return;
	}

	go(here + 1, calc(oper[here], sum, num[here + 1]));
	if (here + 2 < num.size()) {
		int temp = calc(oper[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, calc(oper[here], sum, temp));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}

	go(0, num[0]);
	cout << ret;
}