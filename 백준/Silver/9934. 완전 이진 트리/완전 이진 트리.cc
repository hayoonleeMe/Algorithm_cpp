#include <bits/stdc++.h>
using namespace std;

int k, t;
vector<int> v;
vector<int> ret[12];

void go(int st, int en, int level) {
	if (st == en) {
		ret[level].push_back(v[st]);
		return;
	}
	int mid = (st + en) / 2;
	go(mid, mid, level);
	go(st, mid - 1, level + 1);
	go(mid + 1, en, level + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 0; i < pow(2, k) - 1; ++i) {
		cin >> t;
		v.push_back(t);
	}
	go(0, v.size() - 1, 0);
	for (int i = 0; i < k; ++i) {
		for (int n : ret[i])
			cout << n << ' ';
		cout << '\n';
	}
}