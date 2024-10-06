#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, t, s, e, ret;
int v[100'003];
bool vis[100'003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	while (e < n) {
		if (!vis[v[e]]) {
			vis[v[e]] = 1;
			++e;
		} else {
			ret += e - s;
			vis[v[s]] = 0;
			++s;
		}
	}
	ret += (e - s) * (e - s + 1) / 2;
	cout << ret;
}