#include <bits/stdc++.h>
using namespace std;

int N, S;
int a[100'002];
int mn = 0x7fffffff;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	int en = 0;
	int sum = a[0];
	for (int st = 0; st < N; ++st)
	{
		while (en < N && sum < S)
		{
			++en;
			if (en != N)
				sum += a[en];
		}
		if (en == N)
			break;

		mn = min(mn, en - st + 1);
		sum -= a[st];
	}
	if (mn == 0x7fffffff)
		mn = 0;
	cout << mn;
}