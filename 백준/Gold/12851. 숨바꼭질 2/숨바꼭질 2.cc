#include <bits/stdc++.h>
using namespace std;
const int MAX = 100'000;
int N, K;
int dist[100005];
queue<int> q;
int cnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	fill(dist, dist + 100005, -1);

	dist[N] = 0;
	q.push(N);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == K)
		{
			++cnt;
			continue;
		}

		for (int nxt : { 2 * cur, cur - 1, cur + 1 })
		{
			if (nxt < 0 || nxt > MAX)
				continue;

			if (dist[nxt] == -1 || dist[cur] + 1 <= dist[nxt])
			{
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
			// 이미 정해진 dist[K]가 최소
			else if (nxt == K && dist[cur] + 1 == dist[nxt])
			{
				q.push(nxt);
			}
		}
	}

	cout << dist[K] << '\n' << cnt;
}