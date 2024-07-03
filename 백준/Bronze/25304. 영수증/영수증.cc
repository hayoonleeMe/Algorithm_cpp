#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int X, N;
	cin >> X >> N;
	int sum = 0;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	if (X == sum)
		cout << "Yes";
	else
		cout << "No";
}