#include <bits/stdc++.h>
using namespace std;

int N, M, K;
pair<int, int> VC[200'002];

bool Solve(int x)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < K; ++i)
	{
		if (x >= VC[i].second && cnt < N)
		{
			++cnt;
			sum += VC[i].first;
		}
	}
	if (cnt < N)
		return false;
	return sum >= M;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
		cin >> VC[i].first >> VC[i].second;
	sort(VC, VC + K, greater<pair<int, int>>());

	long long st = 1;
	long long en = 0x7fffffff;
	while (st < en)
	{
		long long mid = (st + en) / 2;
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	if (Solve(st))
		cout << st;
	else
		cout << -1;
}