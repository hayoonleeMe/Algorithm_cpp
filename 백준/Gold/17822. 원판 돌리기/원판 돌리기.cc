#include <bits/stdc++.h>
using namespace std;

int n, m, t, q, x, d, k, ret;
vector<int> pan[53];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> q;
			pan[i].push_back(q);
		}
	}
	while (t--) {
		cin >> x >> d >> k;
		for (int i = x; i <= n; i += x) {
			if (d) {	// 반시계
				rotate(pan[i].begin(), pan[i].begin() + k, pan[i].end());
			} else {
				rotate(pan[i].rbegin(), pan[i].rbegin() + k, pan[i].rend());
			}
		}
		int sum = 0, cnt = 0;
		vector<pair<int, int>> cache;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (pan[i][j] == 0) continue;
				sum += pan[i][j];
				++cnt;
				if (i + 1 <= n && pan[i][j] == pan[i + 1][j]) {
					cache.push_back({ i,j });
					cache.push_back({ i + 1,j });
				}
				if (pan[i][j] == pan[i][(j + 1) % m]) {
					cache.push_back({ i,j });
					cache.push_back({ i, (j + 1) % m });
				}
			}
		}
		if (sum == 0) break;
		if (cache.size()) {
			for (auto& p : cache)
				pan[p.first][p.second] = 0;
		} else {
			double av = (double)sum / cnt;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (pan[i][j] == 0) continue;
					if (pan[i][j] > av) pan[i][j]--;
					else if (pan[i][j] < av) pan[i][j]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		ret += accumulate(pan[i].begin(), pan[i].end(), 0);
	cout << ret;
}