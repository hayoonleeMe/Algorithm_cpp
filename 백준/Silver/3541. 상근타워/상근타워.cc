#include <bits/stdc++.h>
using namespace std;

int N, M, u, d;

bool Solve(int mid)
{
	return mid * u + (N - mid) * -d > 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	int ans = 0x7fffffff;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> d;

		int st = 1;
		int en = N;
		while (st < en)
		{
			int mid = (st + en) / 2;
			if (Solve(mid))
				en = mid;
			else
				st = mid + 1;
		}
		ans = min(ans, st * u + (N - st) * -d);
	}
	cout << ans;
}