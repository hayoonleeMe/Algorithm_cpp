#include <bits/stdc++.h>
using namespace std;

struct ss {
	char c;
	int idx;
};

int n, ret, t;
string s;
stack<ss> stk;
bool v[200'003];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') stk.push({ s[i], i });
		else {
			if (stk.size()) {
				if (stk.top().c == '(') {
					v[i] = 1;
					v[stk.top().idx] = 1;
					stk.pop();
				}
			} else {
				continue;
			}
		}
	}
	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		if (!v[i]) {
			flag = 0;
			t = 0;
			continue;
		}
		if (flag) {
			if (v[i]) {
				t += 1;
				if (t % 2 == 0) ret = max(ret, t);
			}
		} else {
			if (v[i]) {
				flag = 1;
				t = 1;
			}
		}
	}
	cout << ret;
}