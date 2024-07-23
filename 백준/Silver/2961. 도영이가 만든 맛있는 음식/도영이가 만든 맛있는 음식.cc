#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
pair<int, int> arr[12];
int a[12];
bool isused[12];
int ans = 0x7f7f7f7f;

void func(int k, int limit)
{
	if (k == limit)
	{
		int s = 1;
		int b = 0;
		for (int i = 0; i < k; ++i)
		{
			auto p = arr[a[i]];
			s *= p.X;
			b += p.Y;
		}
		ans = min(ans, abs(s - b));
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (k == 0 || (!isused[i] && a[k - 1] < i))
		{
			a[k] = i;
			isused[i] = 1;
			func(k + 1, limit);
			isused[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].X >> arr[i].Y;

	for (int i = 1; i <= N; ++i)
		func(0, i);

	cout << ans;
}