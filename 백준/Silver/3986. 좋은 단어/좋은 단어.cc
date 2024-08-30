#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		stack<char> stk;
		for (char c : s) {
			if (!stk.empty() && c == stk.top()) stk.pop();
			else stk.push(c);
		}
		if (stk.empty()) ++ret;
	}
	cout << ret;
}