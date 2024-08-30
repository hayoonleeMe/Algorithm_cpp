#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[15003];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] + a[j] == m) ++ret;
		}
	}
	cout << ret;
}