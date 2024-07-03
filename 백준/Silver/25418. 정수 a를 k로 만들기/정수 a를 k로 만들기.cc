#include <bits/stdc++.h>
using namespace std;

int A, K;
int dist[1000005];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A >> K;
    fill(dist, dist + 1000005, -1);

	dist[A] = 0;
	q.push(A);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : { cur + 1, cur * 2 })
		{
			if (nx > 1000005)
				continue;
			if (dist[nx] != -1)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	cout << dist[K];
}