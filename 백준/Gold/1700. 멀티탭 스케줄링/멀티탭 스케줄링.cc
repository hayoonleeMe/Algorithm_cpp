#include <bits/stdc++.h>
using namespace std;

int n, k, ret, t;
int nxt[103];
vector<int> v, plug;

bool check(int t) {
	for (int i : plug)
		if (i == t) return 1;
	return 0;
}

void update(int i) {
	auto it = find(v.begin() + i + 1, v.end(), v[i]);
	if (it != v.end()) nxt[v[i]] = it - v.begin();
	else nxt[v[i]] = 200;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> t;
		v.push_back(t);
	}
	for (int i = 0; i < k; ++i) {
		if (!check(v[i])) {
			if (plug.size() < n) {
				plug.push_back(v[i]);
			} else {
				int idx = 0;
				for (int j = 1; j < plug.size(); ++j) {
					if (nxt[plug[idx]] < nxt[plug[j]]) idx = j;
				}
				ret++;
				plug[idx] = v[i];
			}
		}
		update(i);
	}
	cout << ret;
}