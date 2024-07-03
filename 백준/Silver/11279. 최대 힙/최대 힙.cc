#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;

		if (x > 0)
			pq.push(x);
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
	}
}