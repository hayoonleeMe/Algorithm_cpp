#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long N;
unordered_map<long long, long long> dist;
queue<long long> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	dist[N] = 0;
	q.push(N);

	while (dist.find(1) == dist.end())
	{
		auto cur = q.front();
		q.pop();

		if (cur % 3 == 0)
		{
			long long nxt = cur / 3;
			if (dist.find(nxt) == dist.end())
			{
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
		if (cur % 2 == 0)
		{
			long long nxt = cur / 2;
			if (dist.find(nxt) == dist.end())
			{
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
		long long nxt = cur - 1;
		if (dist.find(nxt) == dist.end())
		{
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	std::cout << dist[1];
}