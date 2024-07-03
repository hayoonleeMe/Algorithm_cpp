#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int s = (A * 3600 + B * 60 + C * 60) % (24 * 3600);
	int h = s / 3600;
	int m = (s % 3600) / 60;
	cout << h << ' ' << m;
}