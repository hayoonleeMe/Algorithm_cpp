#include <bits/stdc++.h>
using namespace std;

int R, C, N;
int arr[1'000'005];
int board[1005][1005];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	int offset = 0;
	bool ret = false;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			int index = upper_bound(arr + offset, arr + N, board[i - 1][j]) - arr;
			if (index >= N)
			{
				ret = true;
				break;
			}

			offset = index + 1;
			board[i][j] = arr[index];
			++ans;
		}
		if (ret)
			break;
	}

	cout << ans;
}