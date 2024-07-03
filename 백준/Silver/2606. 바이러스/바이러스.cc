#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> g[105];
bool vis[105];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vis[1] = 1;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (const int& n : g[cur])	 
		{
			if (vis[n])
				continue;

			vis[n] = 1;
			q.push(n);
		}
	}

	int ans = 0;
	for (int i = 2; i <= N; ++i)
		if (vis[i])
			++ans;

	cout << ans;
}