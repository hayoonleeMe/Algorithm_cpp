#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int dist[1000002];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	fill(dist, dist + 1000002, -1);

	++dist[S];
	q.push(S);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
			
		for (int nx : { cur + U, cur - D })
		{
			if (nx < 1 || nx > F)
				continue;
			if (dist[nx] >= 0)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	if (dist[G] == -1)
		cout << "use the stairs";
	else
		cout << dist[G];
}