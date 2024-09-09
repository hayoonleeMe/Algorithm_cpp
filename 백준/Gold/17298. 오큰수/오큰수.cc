#include <bits/stdc++.h>
using namespace std;

int n, t;
stack<pair<int, int>> stk;
int ret[1000003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	fill(ret, ret + n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		while (!stk.empty() && stk.top().second < t) {
			ret[stk.top().first] = t;
			stk.pop();
		}
		stk.push({ i, t });
	}
	for (int i = 0; i < n; ++i)
		cout << ret[i] << ' ';
}