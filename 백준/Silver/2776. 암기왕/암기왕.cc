#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1000003], b[1000003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> b[i];
		sort(a, a + n);
		for (int i = 0; i < m; ++i)
			cout << binary_search(a, a + n, b[i]) << '\n';
	}
}