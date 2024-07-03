#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	double x;
	cin >> x;

	double ans = (378.5411784 / (1.609344 * x));
	cout << fixed;
	cout.precision(6);
	cout << ans;
}