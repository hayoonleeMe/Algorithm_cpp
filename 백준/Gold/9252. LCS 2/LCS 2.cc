#include <bits/stdc++.h>
using namespace std;

string A, B;
int d[1002][1002];

void LCS(int i, int j)
{
	if (i <= 0 || j <= 0)
		return;

	if (A[i - 1] == B[j - 1])
	{
		LCS(i - 1, j - 1);
		cout << A[i - 1];
	}
	else
	{
		if (d[i - 1][j] > d[i][j - 1])
			LCS(i - 1, j);
		else
			LCS(i, j - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A >> B;
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[A.size()][B.size()] << '\n';

	if (d[A.size()][B.size()] > 0)
		LCS(A.size(), B.size());
}