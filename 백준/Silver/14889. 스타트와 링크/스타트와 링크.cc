#include <bits/stdc++.h>
using namespace std;

int n, ret = 987654321;
int a[23][23];
bool t[23];	// 0 : s, 1 : l

void solve() {
	vector<int> t1, t2;
	for (int i = 1; i <= n; ++i) {
		if (t[i]) t1.push_back(i);
		else t2.push_back(i);
	}
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = i + 1; j < n / 2; ++j) {
			s1 += a[t1[i]][t1[j]] + a[t1[j]][t1[i]];
			s2 += a[t2[i]][t2[j]] + a[t2[j]][t2[i]];
		}
	}
	ret = min(ret, abs(s1 - s2));
}

void combi(int depth, int size) {
	if (size == n / 2) {
		solve();
		return;
	}
	for (int i = depth + 1; i <= n; ++i) {
		t[i] = 1;
		combi(i, size + 1);
		t[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	combi(0, 0);
	cout << ret;
}