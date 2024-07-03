#include <bits/stdc++.h>
using namespace std;

int N;
int a[100'002];
int ans = 0x7fffffff;
int A, B;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	for (int i = 0; i < N; ++i)
	{
		int st = i + 1;
		int en = N;
		while (st < en)
		{
			int mid = (st + en) / 2;
			int sum = a[i] + a[mid];
			if (abs(sum) < ans)
			{
				ans = abs(sum);
				A = a[i];
				B = a[mid];
			}

			if (sum < 0)
				st = mid + 1;
			else
				en = mid;
		}
	}
	cout << A << ' ' << B;
}