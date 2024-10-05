#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;	// en, st

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end());
	int cur = v[0].first;
	++ret;
	for (int i = 1; i < n; ++i) {
		if (cur <= v[i].second) {
			cur = v[i].first;
			++ret;
		}
	}
	cout << ret;
}