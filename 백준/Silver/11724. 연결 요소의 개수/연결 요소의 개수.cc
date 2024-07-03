#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> g[1005];
bool vis[1005];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (vis[i])
			continue;

		vis[i] = 1;
		q.push(i);
		++ans;

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
	}

	cout << ans;
}