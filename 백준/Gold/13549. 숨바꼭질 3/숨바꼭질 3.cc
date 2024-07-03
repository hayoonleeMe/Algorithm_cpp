#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[200002];
deque<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	memset(dist, -1, sizeof(dist));

	dist[N] = 0;
	q.push_back(N);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();

		if (2 * cur < 200000 && dist[2 * cur] == -1)
		{
			dist[2 * cur] = dist[cur];
			q.push_front(2 * cur);
		}

		for (int nx : { cur - 1, cur + 1 })
		{
			if (nx < 0 || nx >= 200000)
				continue;
			if (dist[nx] >= 0)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push_back(nx);
		}
	}

	cout << dist[K];
}