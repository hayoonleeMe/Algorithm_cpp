#include <bits/stdc++.h>
using namespace std;

int N;
int a[3002];
int ans = -1;
int gap = 0;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);

	int start = 0;
	int end = 1;
	while (end <= N-1)
	{
		if (a[start] + 1 == a[end] || a[end] - 1 == a[start])
		{
			++start;
			++end;
			continue;
		}

		int half = (a[start] + 1 + a[end] - 1) / 2;
		if (gap < half - a[start])
		{
			gap = half - a[start];
			ans = half;
		}

		++start;
		++end;
	}

	cout << ans;
}