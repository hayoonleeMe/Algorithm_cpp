#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int mid;
	for (int i = 1; i <= N; ++i)
	{
		int n; cin >> n;

		if (i == 1)
			mid = n;
		else if (min_pq.empty())
		{
			if (mid > n)
				swap(mid, n);
			min_pq.push(n); 
		}
		else if (max_pq.empty())
		{
			if (n <= mid)
				max_pq.push(n);
			else
			{
				max_pq.push(mid);
				if (min_pq.top() < n)
				{
					mid = min_pq.top();
					min_pq.pop();
					min_pq.push(n);
				}
				else
					mid = n;
			}
		}
		else if (max_pq.size() == min_pq.size())
		{
			if (mid <= n)
				min_pq.push(n);
			else
			{
				min_pq.push(mid);
				if (max_pq.top() <= n)
					mid = n;
				else
				{
					mid = max_pq.top();
					max_pq.push(n);
					max_pq.pop();
				}
			}
		}
		else if (max_pq.size() < min_pq.size())
		{
			if (mid < n)
			{
				max_pq.push(mid);
				if (min_pq.top() < n)
				{
					mid = min_pq.top();
					min_pq.push(n);
					min_pq.pop();
				}
				else
					mid = n;
			}
			else
				max_pq.push(n);
		}

		cout << mid << '\n';
	}
}