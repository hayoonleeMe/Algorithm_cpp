#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[100005];
bool vis[100005];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> s;

	vis[s] = 1;
	q.push(s);

	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : { cur + a[cur], cur - a[cur] })
		{
			if (nx <= 0 || nx > n)
				continue;
			if (vis[nx] != 0)
				continue;

			vis[nx] = 1;
			q.push(nx);
			++cnt;
		}
	}

	cout << cnt;
}