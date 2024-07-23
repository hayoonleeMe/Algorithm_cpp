#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t;
pair<int, int> st;
pair<int, int> en;
bool vis[102];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--)
	{
		fill(vis, vis + 100, 0);

		int N;
		cin >> N >> st.X >> st.Y;

		vector<pair<int, int>> cs;
		queue<pair<int, int>> q;

		// 편의점들 + 도착
		for (int i = 0; i < N; ++i)
		{
			int x, y;
			cin >> x >> y;
			cs.push_back({ x, y });
		}
		cin >> en.X >> en.Y;

		bool isend = false;
		q.push(st);
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();

			int end_dis = abs(en.X - cur.X) + abs(en.Y - cur.Y);
			if (end_dis <= 1000)
			{
				isend = true;
				break;
			}

			for (int i = 0; i < N; ++i)
			{
				if (vis[i])
					continue;

				int dis = abs(cs[i].X - cur.X) + abs(cs[i].Y - cur.Y);
				if (dis > 1000)
					continue;

				vis[i] = 1;
				q.push(cs[i]);
			}
		}
		if (isend)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}