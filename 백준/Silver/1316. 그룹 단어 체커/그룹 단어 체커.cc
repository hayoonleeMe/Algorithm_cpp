#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;
bool alpha[30];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> s;
		memset(alpha, 0, sizeof(alpha));
		char prev = 0;
		bool bSuccess = true;
		for (char c : s) {
			if (c != prev) {
				if (alpha[c - 'a']) {
					bSuccess = false;
					break;
				}
				alpha[c - 'a'] = 1;
				prev = c;
			}
		}
		if (bSuccess) ++ans;
	}
	cout << ans;
}