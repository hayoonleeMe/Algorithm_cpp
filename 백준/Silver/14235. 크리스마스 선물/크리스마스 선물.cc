#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.size() == 0)
				cout << -1 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			while (x--)
			{
				int v;
				cin >> v;
				pq.push(v);
			}
		}
	}
}