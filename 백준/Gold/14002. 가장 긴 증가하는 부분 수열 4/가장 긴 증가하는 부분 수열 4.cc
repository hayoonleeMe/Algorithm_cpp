#include <bits/stdc++.h>
using namespace std;

int n;
int v[1003], dp[1003], pre[1003];
vector<int> path;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		pre[i] = i;
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
	}
	auto mx = max_element(dp, dp + n);
	int cur = mx - dp;
	while (dp[cur] > 1) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	cout << *mx << '\n';
	for (int i = path.size() - 1; i >= 0; --i)
		cout << v[path[i]] << ' ';
}