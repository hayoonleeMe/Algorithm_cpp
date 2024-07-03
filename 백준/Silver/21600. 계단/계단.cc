#include <bits/stdc++.h>
using namespace std;

int N;
int a[100'002];
int d[100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = d[i-1]; j >= 0; --j)
			if (j + 1 <= a[i])
			{
				d[i] = j + 1;
				break;
			}
	}

	cout << *max_element(d, d + N + 1);
}