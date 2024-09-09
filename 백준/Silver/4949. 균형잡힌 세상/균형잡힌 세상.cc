#include <bits/stdc++.h>
using namespace std;

string s;

bool check(const string& a) {
	stack<char> stk;
	for (char c : a) {
		if (c == '(' || c == '[') stk.push(c);
		else if (c == ')' || c == ']') {
			if (c == ')' && stk.size() && stk.top() == '(') stk.pop();
			else if (c == ']' && stk.size() && stk.top() == '[') stk.pop();
			else return false;
		}
	}
	return stk.empty();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (getline(cin, s); s != "."; getline(cin, s)) {
		if (check(s)) cout << "yes\n";
		else cout << "no\n";
	}
}