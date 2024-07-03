#include <bits/stdc++.h>
using namespace std;

int N;
int d[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	d[1] = 0;
	d[2] = 1;
	d[3] = 0;
	d[4] = 0;

	for (int i = 5; i <= N; ++i)
	{
		for (int j : { 1, 3, 4 })
		{
			if (d[i - j] == 1)
			{
				d[i] = 0;
				break;
			}
			d[i] = 1;
		}
	}

	cout << (d[N] == 0 ? "SK" : "CY");
}