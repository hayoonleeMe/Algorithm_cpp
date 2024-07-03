#include <bits/stdc++.h>
using namespace std;

int N, C;
int a[200'002];

bool Solve(int mid)
{
	int cnt = 1;
	int curIdx = 0;
	while (cnt < C)
	{
		int nxtIdx = upper_bound(a + curIdx + 1, a + N, a[curIdx] + mid - 1) - a;
		if (nxtIdx < N)
		{
			curIdx = nxtIdx;
			++cnt;
		}
		else
			break;
	}
	return cnt >= C;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	
	int st = 1;
	int en = a[N - 1] - a[0];
	while (st < en)
	{
		int mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}