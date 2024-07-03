#include <bits/stdc++.h>
using namespace std;

#define HP first
#define W second

int N, ans, cnt;
pair<int, int> arr[10];

void func(int k)
{
	if (k == N)
	{
		ans = max(ans, cnt);
		return;
	}

	if (arr[k].HP <= 0 || cnt == N - 1)
	{
		func(k + 1);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (i == k || arr[i].HP <= 0)
			continue;

		arr[k].HP -= arr[i].W;
		arr[i].HP -= arr[k].W;	
		if (arr[k].HP <= 0)
			++cnt;
		if (arr[i].HP <= 0)
			++cnt;

		func(k + 1);

		if (arr[k].HP <= 0)
			--cnt;
		if (arr[i].HP <= 0)
			--cnt;
		arr[k].HP += arr[i].W;
		arr[i].HP += arr[k].W;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int s, w;
		cin >> s >> w;
		arr[i] = { s, w };
	}

	func(0);

	cout << ans;
}