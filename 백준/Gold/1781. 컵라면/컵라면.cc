#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<int> v[200'003];
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d >> p;
		v[d].push_back(p);
	}
	for (int i = 200000; i >= 1; --i) {
		if (v[i].size()) {
			for (int j : v[i]) pq.push(j);
		}
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
}