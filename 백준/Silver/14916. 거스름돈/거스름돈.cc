#include <bits/stdc++.h>
using namespace std;

int N;
int d[100'002];
const int MAX = 0x7fffffff;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	d[0] = d[1] = d[3] = -1;
	d[2] = 1;
	d[4] = 2;
	d[5] = 1;

	for (int i = 6; i <= N; ++i)
	{
		d[i] = MAX;

		for (int j = i / 5; j >= 1; --j)
			if (d[i - j * 5] > 0)
			{
				d[i] = min(d[i], j + d[i - j * 5]);
				break;
			}

		for (int j = i / 2; j >=1; --j)
			if (d[i - j * 2] > 0)
			{
				d[i] = min(d[i], j + d[i - j * 2]);
				break;
			}

		if (d[i] == MAX)
			d[i] = -1;
	}

	cout << d[N];
}