#include <bits/stdc++.h>
using namespace std;

int n, ret, st, en, sum;
bool che[4'000'001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	vector<int> v;
	for (int i = 2; i <= n; ++i) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i)
			che[j] = 1;
	}
	for (int i = 2; i <= n; ++i)	
		if (!che[i]) v.push_back(i);

	while (1) {
		if (sum >= n) sum -= v[st++];
		else if (en == v.size()) break;
		else sum += v[en++];
		if (sum == n) ++ret;
	}
	cout << ret;
}