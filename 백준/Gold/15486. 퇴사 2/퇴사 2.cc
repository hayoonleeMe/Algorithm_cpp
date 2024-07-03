#include <bits/stdc++.h>
using namespace std;

#define T first
#define P second

int N;
pair<int, int> arr[1500005];
int d[1500005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t, p;
		cin >> t >> p;
		arr[i] = { t, p };
	}

	for (int i = N; i > 0; --i)
	{
		if (i + arr[i].T > N + 1)
		{
			d[i] = d[i + 1];
			continue;
		}

		d[i] = max(arr[i].P + d[i + arr[i].T], d[i + 1]);
	}

	cout << *max_element(d + 1, d + N + 1);
}