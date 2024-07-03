#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int N, M, K;
char board[15][15];

vector<string> targets;
unordered_map<string, int> counts;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < K; ++i)
	{
		string s; cin >> s;
		targets.push_back(s);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			stack<tuple<int, int, string>> s;
			s.push({ i, j, { board[i][j] } });

			while (!s.empty())
			{
				tuple<int, int, string> cur = s.top();
				s.pop();
				const string& str = get<2>(cur);
				counts[str] += 1;

				if (str.size() == 5)
					continue;

				for (int dir = 0; dir < 8; ++dir)
				{
					int nx = (get<0>(cur) + dx[dir] + N) % N;
					int ny = (get<1>(cur) + dy[dir] + M) % M;
					s.push({ nx, ny, str + board[nx][ny] });
				}
			}
		}
	}

	for (int i = 0; i < K; ++i)
		cout << counts[targets[i]] << '\n';
}