#include <bits/stdc++.h>
using namespace std;

int n, k, a, b;
// 시간, 모금액
pair<int, int> A[103];
pair<int, int> B[103];
int dp[103][100003];

int go(int idx, int x) {
	if (idx >= n) return 0;
	int& ret = dp[idx][x];
	if (ret != -1) return ret;
	ret = -1e9;
	if (x >= A[idx].first)
		ret = max(ret, go(idx + 1, x - A[idx].first) + A[idx].second);
	if (x >= B[idx].first)
		ret = max(ret, go(idx + 1, x - B[idx].first) + B[idx].second);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		A[i] = { a, b };
		cin >> a >> b;
		B[i] = { a, b };
	}
	cout << go(0, k);
}