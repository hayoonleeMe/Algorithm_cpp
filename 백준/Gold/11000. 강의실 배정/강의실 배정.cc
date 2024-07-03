#include <bits/stdc++.h>
using namespace std;

int N, s, t;
pair<int, int> a[200'002];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> s >> t;
		a[i] = { s, t };
	}

	sort(a, a + N);

	pq.push(a[0].second);

	for (int i = 1; i < N; ++i)
	{
		if (a[i].first >= pq.top())
		{
			pq.pop();
			pq.push(a[i].second);
		}
		else
			pq.push(a[i].second);
	}

	cout << pq.size();
}