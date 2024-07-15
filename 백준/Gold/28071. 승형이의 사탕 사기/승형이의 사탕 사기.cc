#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int arr[305];
int dist[90005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	fill(dist, dist + 90005, -1);

	queue<int> q;
	dist[0] = 0;
	q.push(0);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < N; ++i)
		{
			int nx = cur + arr[i];
			if (nx > 90000 || dist[nx] >= 0)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	for (int i = 90000; i >= 0; --i)
	{
		if (i % K == 0 && dist[i] != -1 && dist[i] <= M)
		{
			cout << i;
			return 0;
		}
	}
}