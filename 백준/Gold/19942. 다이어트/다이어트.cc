#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
int n, mp, mf, ms, mv, retSum = INF;
int a[17][5];
vector<int> ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> a[i][j];
	}

	for (int i = 0; i < (1 << n); ++i) {
		int p = 0, f = 0, s = 0, v = 0, sum = 0;
		vector<int> t;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				p += a[j][0];
				f += a[j][1];
				s += a[j][2];
				v += a[j][3];
				sum += a[j][4];
				t.push_back(j + 1);
			}
		}
		if (p >= mp && f >= mf && s >= ms && v >= mv) {
			if (sum < retSum) {
				retSum = sum;
				ret = t;
			}
			else if (sum == retSum && t < ret) {
				ret = t;
			}
		}
	}
	if (retSum == INF) cout << -1;
	else {
		cout << retSum << '\n';
		for (int a : ret)
			cout << a << ' ';
	}
}