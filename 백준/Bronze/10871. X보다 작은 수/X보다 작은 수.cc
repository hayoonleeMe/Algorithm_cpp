#include <bits/stdc++.h>
using namespace std;

int N, X, t;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> X;
	while (N--)
	{
		cin >> t;
		if (t < X)
			cout << t << ' ';
	}
}