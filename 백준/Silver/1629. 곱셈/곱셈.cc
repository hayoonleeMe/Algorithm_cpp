#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C;

ll go(ll a, ll b) {
	if (b == 1) return a % C;

	ll ret = go(a, b / 2);
	ret = (ret * ret) % C;
	if (b % 2) ret = (ret * a) % C;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;
	cout << go(A, B);
}