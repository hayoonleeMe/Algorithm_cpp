#include <bits/stdc++.h>
using namespace std;

int over, t;
string a, b, c;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int i = 0;
	for (; i < min(a.size(), b.size()); ++i) {
		t = (int)(a[i] - '0') + (int)(b[i] - '0') + over;
		c += to_string(t % 10);
		over = t / 10;
	}
	if (a.size() > b.size()) {
		for (; i < a.size(); ++i) {
			t = (int)(a[i] - '0') + over;
			c += to_string(t % 10);
			over = t / 10;
		}
	} else if (a.size() < b.size()) {
		for (; i < b.size(); ++i) {
			t = (int)(b[i] - '0') + over;
			c += to_string(t % 10);
			over = t / 10;
		}
	}
	if (over) c += to_string(over);
	reverse(c.begin(), c.end());
	cout << c;
}