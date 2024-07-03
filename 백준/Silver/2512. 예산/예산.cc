#include <bits/stdc++.h>
using namespace std;

int N;
int a[10'002];
long long total;

bool Solve(long long mid)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i)
		sum += min((long long)a[i], mid);
	return sum <= total;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	cin >> total;

	long long st = 1;
	long long en = *max_element(a, a + N);
	while (st < en)	
	{
		long long mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}