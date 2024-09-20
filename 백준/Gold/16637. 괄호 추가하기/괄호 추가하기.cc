#include <bits/stdc++.h>
using namespace std;

int n, ret = INT_MIN;
string s;
vector<int> op_idx, pr;
stack<char> stk_ator;
stack<int> stk_rand;

bool isOp(char c) {
	return c == '+' || c == '-' || c == '*';
}

void consume() {
	while (stk_ator.size()) {
		char op = stk_ator.top(); stk_ator.pop();
		int rand2 = stk_rand.top(); stk_rand.pop();
		int rand1 = stk_rand.top(); stk_rand.pop();
		if (op == '+') rand1 += rand2;
		if (op == '-') rand1 -= rand2;
		if (op == '*') rand1 *= rand2;
		stk_rand.push(rand1);
	}
}

void go() {
	for (int i = 0; i < s.size(); ++i) {
		if (pr[i] == 2) {
			stk_rand.push((int)(s[i] - '0'));
			stk_rand.push((int)(s[i + 2] - '0'));
			stk_ator.push(s[i + 1]);
			consume();
			i += 2;
			continue;
		}

		if (isOp(s[i])) stk_ator.push(s[i]);
		else stk_rand.push((int)(s[i] - '0'));
		if (stk_rand.size() >= 2) consume();
	}
	consume();
	const int t = stk_rand.top(); stk_rand.pop();
	ret = max(ret, t);
}

void combi(int start, int r, int cnt) {
	if (cnt == r) {
		go();
		return;
	}

	for (int i = start + 2; i < op_idx.size(); ++i) {
		pr[op_idx[i] - 1] = pr[op_idx[i]] = pr[op_idx[i] + 1] = 2;
		combi(i, r, cnt + 1);
		pr[op_idx[i] - 1] = pr[op_idx[i]] = pr[op_idx[i] + 1] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (isOp(s[i])) op_idx.push_back(i);
		pr.push_back(1);
	}

	const int max_pa = (op_idx.size() + 1) / 2;
	for (int pa = 0; pa <= max_pa; ++pa) {
		combi(-2, pa, 0);
	}
	cout << ret;
}