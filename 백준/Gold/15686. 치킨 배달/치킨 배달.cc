#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[52][52];
vector<pair<int, int>> chs;
vector<pair<int, int>> house;
int ans = 0x7fffffff;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				chs.push_back({ i, j });
			else if (board[i][j] == 1)
				house.push_back({ i, j });
		}
	}

	// 1이 M개, 나머지는 0 => 1일 때 뽑은놈
	vector<int> temp(chs.size(), 1);
	fill(temp.begin(), temp.begin() + chs.size() - M, 0);

	do
	{
		int tot = 0;
		for (pair<int, int>& h : house)
		{
			int mn = 0x7fffffff;
			for (int i = 0; i < chs.size(); ++i)
			{
				if (temp[i] == 1)
				{
					int length = abs(h.first - chs[i].first) + abs(h.second - chs[i].second);
					mn = min(mn, length);
				}
			}
			tot += mn;
		}
		ans = min(ans, tot);
	} while (next_permutation(temp.begin(), temp.end()));

	cout << ans;
}	