#include <bits/stdc++.h>
using namespace std;

int n, m, j, pos, nxt, ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> j;
	pos = 1;
	while (j--) {
		cin >> nxt;

		if (pos <= nxt && nxt <= pos + m - 1) continue;
		if (pos < nxt) {
			int cur = pos + m - 1;
			ret += nxt - cur;
			pos += nxt - cur;
		}
		else {
			ret += pos - nxt;
			pos = nxt;
		}
	}
	cout << ret;
}