#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ret;
int n, t;
stack<pair<int, ll>> stk;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;

		int cnt = 1;
		while (stk.size() && stk.top().first <= t) {
			ret += stk.top().second;
			if (stk.top().first == t) {
				cnt = stk.top().second + 1;
			} else {
				cnt = 1;
			}
			stk.pop();
		}
		if (stk.size()) ++ret;
		stk.push({ t, cnt });
	}
	cout << ret;
}