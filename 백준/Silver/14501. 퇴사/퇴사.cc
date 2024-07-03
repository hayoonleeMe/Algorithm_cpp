#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[20];
int d[20];

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

	for (int i = 1; i <= N; ++i)
	{
		if (i + arr[i].first > N + 1)
			continue;

		d[i] = arr[i].second;
		for (int j = i - 1; j > 0; --j)
			if (j + arr[j].first <= i)
				d[i] = max(d[i], d[j] + arr[i].second);
	}

	cout << *max_element(d + 1, d + N + 1);
}