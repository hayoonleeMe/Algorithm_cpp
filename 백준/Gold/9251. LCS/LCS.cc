#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
string A, B;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A >> B;
	int an = A.size(), bn = B.size();

	for (int i = 1; i <= an; ++i)
	{
		for (int j = 1; j <= bn; ++j)
		{
			if (A[i - 1] == B[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[an][bn];
}