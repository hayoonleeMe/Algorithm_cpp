#include <bits/stdc++.h>
using namespace std;

int m, x, s;
string str;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m;
	while (m--) {
		cin >> str;
		if (str == "all") {
			s = (1 << 21) - 1;
		} else if (str == "empty") {
			s = 0;
		} else {
			cin >> x;
			int a = (1 << x);
			if (str == "add") {
				if (!(s & a)) s |= a;
			} else if (str == "remove") {
				if (s & a) s &= ~(a);
			} else if (str == "check") {
				cout << (bool)(s & a) << '\n';
			} else if (str == "toggle") {
				s ^= a;
			}
		}
	}
} 