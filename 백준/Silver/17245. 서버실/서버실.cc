#include <bits/stdc++.h>
using namespace std;

int N;
int a[1002][1002];
long long total;

bool Solve(int x)
{
	double sum = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			sum += min(x, a[i][j]);

	return (sum / total) >= 0.5;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> a[i][j];
			total += a[i][j];
		}
	}
		
	int st = 0;
	int en = 10'000'000;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (Solve(mid))
			en = mid;
		else
			st = mid + 1;
	}
	if (Solve(st))
		cout << st;
	else
		cout << 0;
}