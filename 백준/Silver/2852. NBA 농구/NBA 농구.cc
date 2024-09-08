#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, t, g1, g2, ret1, ret2;
string s, prev;

void print(int ret) {
	int m1 = ret / 600;
	int m2 = (ret % 600) / 60;
	int s1 = (ret % 60) / 10;
	int s2 = (ret % 60) % 10;
	cout << m1 << m2 << ":" << s1 << s2 << '\n';
}

int getSec(const string& s) {
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

void go(int& ret, string s) {
	ret += getSec(s) - getSec(prev);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t >> s;
		if (g1 > g2) go(ret1, s);
		else if (g1 < g2) go(ret2, s);
		t == 1 ? g1++ : g2++;
		prev = s;
	}
	if (g1 > g2) go(ret1, "48:00");
	else if (g1 < g2) go(ret2, "48:00");

	print(ret1);
	print(ret2);
}