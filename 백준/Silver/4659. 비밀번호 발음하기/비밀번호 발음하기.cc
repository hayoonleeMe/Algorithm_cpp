#include <bits/stdc++.h>
using namespace std;

#define prev aaaa

bool accept, vowel;
int cnt;
char prev;
string s;

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (cin >> s; s != "end"; cin >> s) {
		accept = true;
		cnt = 1;
		prev = s[0];
		vowel = isvowel(prev);

		for (int i = 1; i < s.size(); ++i) {
			char cur = s[i];
			if (isvowel(cur)) vowel = true;

			if ((isvowel(prev) && isvowel(cur)) || (!isvowel(prev) && !isvowel(cur))) {
				++cnt;
			} else {
				cnt = 1;
			}
			if (cnt == 3) {
				accept = false;
				break;
			}

			if (prev == cur && cur != 'e' && cur != 'o') {
				accept = false;
				break;
			}
			prev = cur;
		}
		if (!vowel) accept = false;

		if (accept) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}
}