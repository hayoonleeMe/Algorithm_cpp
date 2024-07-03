#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int graph[1002][1002];
int visited[1002];
queue<int> q;

void Dfs(int v)
{
	visited[v] = 1;
	cout << v << ' ';

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] != 1 && graph[v][i])
			Dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// DFS
	Dfs(V);
	cout << '\n';

	// BFS
	memset(visited, 0, sizeof(visited));

	visited[V] = 1;
	q.push(V);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i = 1; i <= N; ++i)
		{
			if (graph[cur][i] && visited[i] != 1)
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}