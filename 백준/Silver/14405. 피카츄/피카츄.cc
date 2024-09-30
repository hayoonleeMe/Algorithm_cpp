#include <bits/stdc++.h>
using namespace std;

string s;
bool flag;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size();) {
		if (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") {
			i += 2;
		} else if (s.substr(i, 3) == "chu") {
			i += 3;
		} else {
			flag = 1;
			break;
		}
	}
	if (flag) cout << "NO\n";
	else cout << "YES\n";
}