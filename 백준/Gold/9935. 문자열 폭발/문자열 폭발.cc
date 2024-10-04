#include <bits/stdc++.h>
using namespace std;

string a, b, ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	for (char c : a) {
		ret += c;
		if (ret.size() >= b.size()) {
			int cur = ret.find(b, ret.size() - b.size());
			if (cur != string::npos)
				ret.erase(cur, b.size());
		}
	}
	if (ret.empty()) cout << "FRULA";
	else cout << ret;
}