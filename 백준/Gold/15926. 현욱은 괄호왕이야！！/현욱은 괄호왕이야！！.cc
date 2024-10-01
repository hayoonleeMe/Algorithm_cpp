#include <bits/stdc++.h>
using namespace std;

int n, ret, t;
string s;
stack<int> stk;
bool v[200'003];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') stk.push(i);
		else if (stk.size()) {
			v[i] = v[stk.top()] = 1;
			stk.pop();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!v[i]) {
			t = 0;
		} else {
			t += 1;
			if (t % 2 == 0) ret = max(ret, t);
		}
	}
	cout << ret;
}