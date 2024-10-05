#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, a, b, c, cur;
ll ret;
vector<pair<int, int>> v;
vector<int> bags;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k; ++i) {
		cin >> c;
		bags.push_back(c);
	}
	sort(bags.begin(), bags.end());
	for (int i : bags) {
		for (; cur < n; ++cur) {
			if (v[cur].first > i) break;
			pq.push(v[cur].second);
		}
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
}