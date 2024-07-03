#include <bits/stdc++.h>
using namespace std;

long long X, Y;
int Z;

bool Solve(long long mid)
{
	int gap = mid - X;
	int t = (Y + gap) * 100 / mid;
	return t > Z;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> X >> Y;
	Z = Y * 100 / X;

	long long st = X + 1;
	long long en = 2 * X;
	while (st < en)
	{
		long long mid = (st + en) / 2;
		
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	if (Solve(st))
		cout << st - X;
	else
		cout << -1;
}