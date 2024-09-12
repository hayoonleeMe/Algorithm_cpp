#include <bits/stdc++.h>
using namespace std;

int n, t, ret = 1e7;
vector<int> v;
vector<int> damage = { 9, 3, 1 };
vector<int> idx = { 0, 1, 2 };

void go(int cnt, vector<int> a) {
	bool flag = 1;
	for (int h : v) {
		if (h > 0) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		ret = min(ret, cnt);
		return;
	}

	do {
		for (int i = 0; i < n; ++i) {
			v[i] -= damage[a[i]];
		}
		go(cnt + 1, a);
		for (int i = 0; i < n; ++i) {
			v[i] += damage[a[i]];
		}
	} while (next_permutation(a.begin(), a.end()));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		v.push_back(t);
	}

	go(0, idx);
	cout << ret;
}