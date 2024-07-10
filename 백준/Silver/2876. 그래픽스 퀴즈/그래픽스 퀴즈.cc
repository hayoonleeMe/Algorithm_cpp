#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100'005];
int d[100'005][6];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	for (int i = 1; i <= N; ++i)
		for (int j : { arr[i].first, arr[i].second })
			d[i][j] = d[i - 1][j] + 1;

	int ans = 0;
	int grade = 10;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			if (ans < d[i][j])
			{
				ans = d[i][j];
				grade = j;
			}
			else if (ans == d[i][j])
				grade = min(grade, j);
		}
	}
	cout << ans << ' ' << grade;
}