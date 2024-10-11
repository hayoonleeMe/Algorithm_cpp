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
		int num = (cur - p.second + 1) % l == 0 ? (cur - p.second + 1) / l : (cur - p.second + 1 + l) / l;
		ret += num;
		last = cur - num * l;
	}
	cout << ret;
}