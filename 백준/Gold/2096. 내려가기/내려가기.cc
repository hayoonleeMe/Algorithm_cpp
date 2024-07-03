#include <bits/stdc++.h>
using namespace std;

int N;
int a, b, c;
int dmax[2][3];
int dmin[2][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b >> c;

		dmax[1][0] = a + max(dmax[0][0], dmax[0][1]);
		dmax[1][1] = b + max({ dmax[0][0], dmax[0][1], dmax[0][2] });
		dmax[1][2] = c + max(dmax[0][1], dmax[0][2]);

		dmax[0][0] = dmax[1][0];
		dmax[0][1] = dmax[1][1];
		dmax[0][2] = dmax[1][2];

		dmin[1][0] = a + min(dmin[0][0], dmin[0][1]);
		dmin[1][1] = b + min({ dmin[0][0], dmin[0][1], dmin[0][2] });
		dmin[1][2] = c + min(dmin[0][1], dmin[0][2]);

		dmin[0][0] = dmin[1][0];
		dmin[0][1] = dmin[1][1];
		dmin[0][2] = dmin[1][2];
	}

	cout << max({ dmax[0][0], dmax[0][1], dmax[0][2] }) << ' ' << min({ dmin[0][0], dmin[0][1], dmin[0][2] });
}