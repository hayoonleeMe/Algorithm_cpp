#include <bits/stdc++.h>
using namespace std;

int N;
int a[2002];
int ans;

void Solve(int i)
{
	for (int j = 0; j < N; ++j)
	{
		if (i == j)
			continue;
		int search = a[i] - a[j];
		int idx = lower_bound(a, a + N, search) - a;
		for (; idx < N && a[idx] == search; ++idx)
		{
			if (idx != i && idx != j)
			{
				++ans;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);

	for (int i = 0; i < N; ++i)
		Solve(i);
	cout << ans;
}