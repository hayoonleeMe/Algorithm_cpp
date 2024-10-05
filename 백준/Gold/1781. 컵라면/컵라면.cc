#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d >> p;
		v.push_back({ d, p });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		ret += v[i].second;
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			ret -= pq.top();
			pq.pop();
		}
	}
	cout << ret;
}