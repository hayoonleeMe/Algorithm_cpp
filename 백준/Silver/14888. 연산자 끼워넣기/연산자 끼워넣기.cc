#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000000;
int n, max_ret = -INF, min_ret = INF, t;
int v[12];
vector<int> idx;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < 4; ++i) {
		cin >> t;
		for (int j = 0; j < t; ++j)
			idx.push_back(i);
	}
	do {
		int sum = v[0], cur = 1;
		for (int op : idx) {
			switch (op) {
			case 0:
				sum += v[cur++];
				break;
			case 1:
				sum -= v[cur++];
				break;
			case 2:
				sum *= v[cur++];
				break;
			case 3:
				sum /= v[cur++];
				break;
			}
		}
		max_ret = max(max_ret, sum);
		min_ret = min(min_ret, sum);
	} while (next_permutation(idx.begin(), idx.end()));
	cout << max_ret << '\n' << min_ret;
}