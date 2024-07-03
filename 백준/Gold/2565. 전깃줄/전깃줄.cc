#include <bits/stdc++.h>
using namespace std;

int N, A, B;
pair<int, int> a[102];
int d[102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A >> B;
		a[i] = { A, B };
	}
	sort(a, a + N + 1);

	for (int i = 1; i <= N; ++i)
	{
		d[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (a[i].second > a[j].second)
				d[i] = max(d[i], d[j] + 1);
		}
	}
	cout << N - *max_element(d, d + N + 1);
}