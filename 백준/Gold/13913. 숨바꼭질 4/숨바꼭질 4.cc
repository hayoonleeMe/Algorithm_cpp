#include <bits/stdc++.h>
using namespace std;
#define MAX 222'222
int N, K;
int dist[MAX];
int back[MAX];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	fill(dist, dist + MAX, -1);

	dist[N] = 0;
	q.push(N);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : { 2 * cur, cur + 1, cur - 1 })
		{
			if (nx < 0 || nx >= MAX)
				continue;

			if (dist[nx] == -1 || dist[cur] + 1 < dist[nx])
			{
				dist[nx] = dist[cur] + 1;
				q.push(nx);
				back[nx] = cur;
			}
		}
	}
	cout << dist[K] << '\n';

	vector<int> rev;
	int pos = K;
	while (1)
	{
		rev.push_back(pos);
		if (pos == N)
			break;
		pos = back[pos];
	}
	
	reverse(rev.begin(), rev.end());
	for (int i : rev)
		cout << i << ' ';
}