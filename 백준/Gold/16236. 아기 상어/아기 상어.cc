#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int board[22][22];
// x, y
list<pair<int, int>> fishes;
int dist[22][22];
// 초기 크기 2
int ssize = 2;
// 먹은 수
int eat = 0;
// 상어 위치
int sx, sy;

void Bfs(int x, int y)
{
	// dist 업데이트
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + N, -1);

	queue<pair<int, int>> q;
	dist[x][y] = 0;
	q.push({ x, y });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (dist[nx][ny] != -1 || board[nx][ny] > ssize)
				continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return board[a.X][a.Y] < board[b.X][b.Y];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				sx = i;
				sy = j;
				board[i][j] = 0;
			}
			else if (board[i][j] != 0)
				fishes.push_back({ i, j });
		}
	}
	// 물고기 크기 오름차순 정렬
	fishes.sort(compare);

	int ans = 0;
	while (1)
	{
		// dist 업데이트
		Bfs(sx, sy);

		// 먹을 물고기 고르기
		if (fishes.empty())
			break;

		int fx = -1, fy = -1;
		int fdist = 0x7f7f7f7f;
		list<pair<int, int>>::iterator fish;
		for (list<pair<int, int>>::iterator it = fishes.begin(); it != fishes.end(); it++)
		{
			// 현재 상어보다 큰 물고기 못먹음
			if (board[it->X][it->Y] >= ssize)
				break;

			// 도달 불가
			if (dist[it->X][it->Y] == -1)
				continue;

			// 거리가 가장 가까운 놈
			if (fdist > dist[it->X][it->Y])
			{
				fdist = dist[it->X][it->Y];
				fx = it->X; 
				fy = it->Y;
				fish = it;
			}
			else if (fdist == dist[it->X][it->Y])
			{
				// 거리가 같으면 위에 있는 놈
				if (it->X < fx)
				{
					fx = it->X;
					fy = it->Y;
					fish = it;
				}
				// 같은 높이면 왼쪽인 놈
				else if (fx == it->X)
				{
					if (it->Y < fy)
					{
						fx = it->X;
						fy = it->Y;
						fish = it;
					}
				}
			}
		}
		// 먹을 수 있는 물고기 X
		if (fx == -1)
			break;

		// 먹음
		fishes.erase(fish);
		board[fx][fy] = 0;
		++eat;
		if (eat == ssize)
		{
			eat = 0;
			++ssize;
		}
		ans += dist[fx][fy];
		// 상어 위치 업데이트
		sx = fx;
		sy = fy;
	}

	cout << ans;
}