#include <bits/stdc++.h>
using namespace std;

int d[25][25][25];

int Solve(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;
	if (a > 20 or b > 20 or c > 20)
		return Solve(20, 20, 20);

	int& ret = d[a][b][c];
	if (ret)
		return ret;

	if (a < b and b < c)
		return ret = Solve(a, b, c - 1) + Solve(a, b - 1, c - 1) - Solve(a, b - 1, c);
	else
		return ret = Solve(a - 1, b, c) + Solve(a - 1, b - 1, c) + Solve(a - 1, b, c - 1) - Solve(a - 1, b - 1, c - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 and b == -1 and c == -1)
			return 0;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << Solve(a, b, c) << '\n';
	}
}