#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define X first
#define Y second

int dx[4] = { 2, 0, -2, 0 };
int dy[4] = { 0, 2, 0, -2 };

int N, K;
set<pair<int, int>> v;
set<pair<int, int>> vis;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.insert({ a, b });
	}

	for (auto k : v)
	{
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = k.X + dx[dir];
			int ny = k.Y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (vis.find({ nx, ny }) != vis.end())
				continue;
			if (v.find({ nx, ny }) != v.end())
				continue;
			vis.insert({ nx, ny });
		}
	}
	cout << vis.size();
}