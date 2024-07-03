#include <bits/stdc++.h>
using namespace std;

int S, C;
int L[1'000'002];

bool Solve(long long mid)
{
	long long cnt = 0;
	for (int i = 0; i < S; ++i)
		cnt += L[i] / mid;
	return cnt >= C;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> S >> C;
	for (int i = 0; i < S; ++i)
		cin >> L[i];

	long long st = 1;
	long long en = 1'000'000'000;
	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}

	long long remain = -st * C;
	for (int i = 0; i < S; ++i)
		remain += L[i];
	cout << remain;
}