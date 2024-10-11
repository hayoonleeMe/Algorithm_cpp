#include <bits/stdc++.h>
using namespace std;

int n, l, a, b, ret, last = 2'000'000'000;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back({ b - 1, a });
	}
	sort(v.begin(), v.end(), greater<>());
	for (auto p : v) {
		int cur = min(last, p.first);
		while (cur >= p.second) {
			++ret;
			for (int i = 0; i < l; ++i) --cur;
		}
		last = cur;
	}
	cout << ret;
}