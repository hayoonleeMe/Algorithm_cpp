#include <bits/stdc++.h>
using namespace std;

int N, W, L;
int tr[1002];
int br[1002];

bool IsBrEmpty()
{
	for (int i = 0; i < W; ++i)
		if (br[i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> W >> L;
	for (int i = 0; i < N; ++i)
		cin >> tr[i];

	int cur = 0;
	int tot = 0;
	int time = 0;
	do
	{
		// move
		for (int i = W - 1; i >= 0; --i)
		{
			if (br[i])
			{
				if (i + 1 >= W)
					tot -= br[i];
				else
					br[i + 1] = br[i];
				br[i] = 0;
			}
		}

		// add
		if (cur < N && tot + tr[cur] <= L)
		{
			if (!br[0])
			{
				br[0] = tr[cur];
				tot += tr[cur];
				++cur;
			}
		}

		++time;
	} while (cur <= N && !IsBrEmpty());

	cout << time;
}