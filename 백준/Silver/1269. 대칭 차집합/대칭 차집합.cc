#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200003], b[200003];
set<int> ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0; i < n; ++i) {
		if (!binary_search(b, b + m, a[i]))
			ret.insert(a[i]);
	}
	for (int i = 0; i < m; ++i) {
		if (!binary_search(a, a + n, b[i]))
			ret.insert(b[i]);
	}
	cout << ret.size();
}