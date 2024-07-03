#include <bits/stdc++.h>
using namespace std;

int N;
int a[1005];
int d[1005];
int idx[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	fill(d, d + N + 1, 1);

	for (int i = 2; i <= N; ++i)
	{
		for (int j = i - 1; j > 0; --j)
		{
			if (a[i] > a[j])
			{
				if (d[i] < d[j] + 1)
				{
					d[i] = d[j] + 1;
					idx[i] = j;
				}
			}
		}
	}

	int* last = max_element(d + 1, d + N + 1);
	cout << *last << '\n';

	stack<int> s;
	int lastIdx = last - d;
	while (lastIdx != 0)
	{
		s.push(a[lastIdx]);
		lastIdx = idx[lastIdx];
	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
}