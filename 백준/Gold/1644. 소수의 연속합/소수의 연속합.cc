#include <bits/stdc++.h>
using namespace std;

int n, ret;

bool check(int i) {
	if (i <= 1) return 0;
	if (i == 2) return 1;
	if (i % 2 == 0) return 0;
	for (int j = 3; j * j <= i; ++j)
		if (i % j == 0) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	int cur = 0;
	queue<int> q;
	for (int i = n; i >= 2; --i) {
		if (check(i)) {
			cur += i;
			q.push(i);
			if (cur > n) {
				cur -= q.front();
				q.pop();
			} else if (cur == n) {
				++ret;
				cur -= q.front(); 
				q.pop();
			}
		}
	}
	cout << ret;
}