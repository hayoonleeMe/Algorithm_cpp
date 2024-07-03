#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[100'002];

bool Solve(int mid)
{
	for (int i = 0; i < M - 1; ++i)
	{
		if ((a[i + 1] - mid) - (a[i] + mid) > 0)
			return false;
	}
	if (a[M - 1] + mid < N)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> a[i];

	int st = a[0];
	int en = 100'000;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	cout << st;
}