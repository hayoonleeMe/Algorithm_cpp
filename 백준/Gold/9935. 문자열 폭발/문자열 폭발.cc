#include <bits/stdc++.h>
using namespace std;

string a, b, ret;
stack<char> stk;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	for (char c : a) {
		stk.push(c);
		if (stk.size() >= b.size() && stk.top() == b[b.size() - 1]) {
			string s = "";
			for (int i = 0; i < b.size(); ++i) {
				s += stk.top();
				stk.pop();
			}
			reverse(s.begin(), s.end());
			if (s != b) {
				for (char cc : s) stk.push(cc);
			}
		}
	}
	if (stk.empty()) cout << "FRULA";
	else {
		while (stk.size()) {
			ret += stk.top();
			stk.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret;
	}
}