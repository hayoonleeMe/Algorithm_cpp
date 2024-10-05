#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		if (ret > v[i].first)
			ret += v[i].second;
		else
			ret = v[i].first + v[i].second;
	}
	cout << ret;
}