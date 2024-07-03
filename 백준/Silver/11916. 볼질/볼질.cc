#include <bits/stdc++.h>
using namespace std;

int N;
bool t[5];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;

	int ball = 0;
	while (N--)
	{
		int a;
		cin >> a;

		if (a == 1)
			++ball;

		if (a == 3)
		{
			++ball;

			if (t[3])
			{
				t[3] = 0;
				++ans;
			}
			if (t[2])
			{
				t[2] = 0;
				t[3] = 1;
			}
			if (t[1])
			{
				t[1] = 0;
				t[2] = 1;
			}
		}

		if (a == 2 || ball == 4)
		{
			// 3루
			if (t[3] && t[2] && t[1])
			{
				t[3] = 0;
				++ans;
			}
			// 2루
			if (t[2] && t[1])
			{
				t[2] = 0;
				t[3] = 1;
			}
			// 1루
			if (t[1])
			{
				t[1] = 0;
				t[2] = 1;
			}

			t[1] = 1;
			ball = 0;
		}
	}

	cout << ans;
}