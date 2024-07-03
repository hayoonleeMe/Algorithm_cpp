#include <bits/stdc++.h>
using namespace std;

int N;
int d[1000005];
int pre[1000005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0)
		{
			if (d[i / 2] + 1 < d[i])
			{
				pre[i] = i / 2;
				d[i] = d[i / 2] + 1;
			}
		}
		if (i % 3 == 0)
		{
			if (d[i / 3] + 1 < d[i])
			{
				pre[i] = i / 3;
				d[i] = d[i / 3] + 1;
			}
		}
	}

	cout << d[N] << '\n';
	int i = N;
	while (1)
	{
		cout << i << ' ';
		if (i == 1)
			break;
		i = pre[i];
	}
}