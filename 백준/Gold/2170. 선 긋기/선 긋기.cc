#include <bits/stdc++.h>
using namespace std;

int n, ret, cur = -1000000003;
pair<int, int> a[1000003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (auto& p : a) {
		cur = max(cur, p.first);
		if (cur >= p.second) continue;
		ret += p.second - cur;
		cur = p.second;
	}
	cout << ret;
}