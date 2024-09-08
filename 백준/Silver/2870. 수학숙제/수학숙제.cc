#include <bits/stdc++.h>
using namespace std;

int n, cnt, st;
string s;
vector<string> ret;

string trim(string a) {
	int st = 0;
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] == '0') ++st;
		else break;
	}
	return a.substr(st);
}

bool compare(const string& a, const string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cnt = st = 0;
		cin >> s;

		for (int i = 0; i < s.size(); ++i) {
			if (isdigit(s[i])) {
				if (cnt == 0) st = i;
				++cnt;
			} else {
				if (cnt) ret.push_back(trim(s.substr(st, cnt)));
				cnt = 0;
			}
		}
		if (cnt) ret.push_back(trim(s.substr(st)));
	}
	sort(ret.begin(), ret.end(), compare);
	for (string a : ret)
		cout << a << '\n';
}