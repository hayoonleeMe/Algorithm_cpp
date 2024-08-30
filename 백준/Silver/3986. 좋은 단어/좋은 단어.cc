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

		stack<char> st;
		for (char c : s) {
			if (st.empty()) st.push(c);
			else {
				if (c == st.top()) st.pop();
				else st.push(c);
			}
		}
		if (st.empty()) ++ret;
	}
	cout << ret;
}