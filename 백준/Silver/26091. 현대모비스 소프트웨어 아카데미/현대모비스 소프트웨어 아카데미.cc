#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[100'002];
bool done[100'002];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);

	int st = 0;
	int en = N - 1;
	while (st < en)
	{
		if (a[st] + a[en] < M)
			++st;
		else
		{
			++ans;
			++st;
			--en;
		}
	}

	cout << ans;
}