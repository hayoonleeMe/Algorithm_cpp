#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	for (char c : s) cnt[c]++;
	for (int i = 'Z'; i >= 'A'; --i) {
		if (cnt[i]) {
			if (cnt[i] & 1) {
				mid = char(i);
				flag++;
				cnt[i]--;
			}
			if (flag == 2) break;

			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2) cout << "I'm Sorry Hansoo";
	else cout << ret;
}