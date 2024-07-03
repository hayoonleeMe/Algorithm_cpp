#include <bits/stdc++.h>
using namespace std;

const int R = 2;
const int L = 6;

string t[5];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 1; i <= 4; ++i)
		cin >> t[i];
	int T;
	cin >> T;
	while (T--)
	{
		int n, d;
		cin >> n >> d;

		int dir[5] = { 0, };
		dir[n] = d;

		// 우측
		for (int r = n + 1; r <= 4; ++r)
		{
			if (t[r - 1][R] != t[r][L])
				dir[r] = dir[r - 1] * -1;
			else
				break;
		}

		// 좌측
		for (int l = n - 1; l >= 1; --l)
		{
			if (t[l + 1][L] != t[l][R])
				dir[l] = dir[l + 1] * -1;
			else
				break;
		}

		// 회전
		for (int i = 1; i <= 4; ++i)
		{
			if (dir[i] == 1)
				rotate(t[i].begin(), t[i].begin() + 7, t[i].end());
			else if (dir[i] == -1)
				rotate(t[i].begin(), t[i].begin() + 1, t[i].end());
		}
	}

	for (int i = 1; i <= 4; ++i)
	{
		int m = (int)(t[i][0] - '0') << (i - 1);
		ans += m;
	}

	cout << ans;
}