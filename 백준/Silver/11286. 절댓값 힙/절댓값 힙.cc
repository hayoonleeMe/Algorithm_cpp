#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		else
			return a > b;
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;

		if (x != 0)
			pq.push(x);
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}