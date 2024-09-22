#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;
char es[10];
bool visited[10];
vector<char> s;
ll mx, mn = 1e12;
string mx_s, mn_s;

void go() {
	if (s.size() == k + 1) {
		string str(s.begin(), s.end());
		ll t = stoll(str);
		if (t > mx) {
			mx = t;
			mx_s = str;
		}
		if (t < mn) {
			mn = t;
			mn_s = str;
		}
		return;
	}

	int st, en;
	int cur = (int)(s.back() - '0');
	if (es[s.size() - 1] == '<') {
		st = cur + 1;
		en = 9;
	} else {
		st = 0;
		en = cur - 1;
	}
	for (int i = st; i <= en; ++i) {
		if (visited[i]) continue;
		visited[i] = 1;
		s.push_back(i + '0');
		go();
		visited[i] = 0;
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> es[i];

	for (int i = 0; i <= 9; ++i) {
		visited[i] = 1;
		s.push_back(i + '0');
		go();
		visited[i] = 0;
		s.pop_back();
	}
	cout << mx_s << '\n' << mn_s;
}