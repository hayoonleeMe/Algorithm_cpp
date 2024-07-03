#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> a[100005];

bool Compare(pair<int, int> A, pair<int, int> B)
{
	if (A.second != B.second)
		return A.second < B.second;
	else
		return A.first < B.first;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int s, e;
		cin >> s >> e;
		a[i] = { s, e };
	}
	sort(a + 1, a + N + 1, Compare);

	int ans = 0, end = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (end <= a[i].first)
		{
			++ans;
			end = a[i].second;
		}
	}

	cout << ans;
}