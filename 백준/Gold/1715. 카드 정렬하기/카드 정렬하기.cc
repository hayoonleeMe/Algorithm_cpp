#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		pq.push(n);
	}

	int ans = 0;
	while (pq.size() != 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
}