#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; ++i)
	{
		int t;
		cin >> t;
		pq.push(t);
		if (pq.size() > N)
			pq.pop();
	}
	cout << pq.top();
}