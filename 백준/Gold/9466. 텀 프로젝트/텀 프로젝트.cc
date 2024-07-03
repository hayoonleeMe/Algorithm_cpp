#include <bits/stdc++.h>
using namespace std;
const int CYCLE = -1;
const int NOT_VIS = 0;
int T, n;
int a[100001];
int vis[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int j = 1; j <= n; ++j)
			cin >> a[j];
		fill(vis + 1, vis + n + 1, NOT_VIS);

		for (int j = 1; j <= n; ++j)
		{
			if (vis[j] != NOT_VIS)
				continue;

			int cur = j;
			while (1)
			{
				vis[cur] = j;
				cur = a[cur];
				if (vis[cur] == j)
				{
					while (vis[cur] != CYCLE)
					{
						vis[cur] = CYCLE;
						cur = a[cur];
					}
					break;
				}

				if (vis[cur] != NOT_VIS)
					break;
			}
		}

		int ans = 0;
		for (int j = 1; j <= n; ++j)
			if (vis[j] != CYCLE)
				++ans;

		cout << ans << '\n';
	}
}