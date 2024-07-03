#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 1;
queue<int> q;
int d[45];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= 40; ++i)
		d[i] = d[i - 1] + d[i - 2];

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int t;
		cin >> t;
		q.push(t);
	}

	int s = 0, e;
	while (!q.empty())
	{
		e = q.front();
		q.pop();
		ans *= d[e - s - 1];
		s = e;
	}
	ans *= d[N - s];

	cout << ans;
}