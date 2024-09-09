#include <bits/stdc++.h>
using namespace std;

int n, t, top1;
stack<int> s1, s2;
int ret[1000003];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		s1.push(t);
	}

	for (int i = n - 1; i >= 0; --i) {
		top1 = s1.top();
		s1.pop();

		for (; !s2.empty() && top1 >= s2.top(); s2.pop());
		if (s2.empty()) ret[i] = -1;
		else ret[i] = s2.top();

		s2.push(top1);
	}

	for (int i = 0; i < n; ++i) {
		cout << ret[i] << ' ';
	}
}