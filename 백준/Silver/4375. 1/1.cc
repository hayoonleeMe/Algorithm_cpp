#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> n)
	{
		ll cnt = 1, ret = 1;
		while (cnt % n)
		{
			cnt = cnt * 10 + 1;
			cnt %= n;
			++ret;
		}
		cout << ret << '\n';
	}
}