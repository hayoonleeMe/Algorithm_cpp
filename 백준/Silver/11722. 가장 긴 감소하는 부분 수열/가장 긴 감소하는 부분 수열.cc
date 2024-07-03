#include <bits/stdc++.h>
using namespace std;

int N;
int a[1002];
int d[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		d[i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{ 
		for (int j = 1; j < i; ++j)
			if (a[i] < a[j])
				d[i] = max(d[i], d[j] + 1);
	}

	cout << *max_element(d + 1, d + N + 1);
}