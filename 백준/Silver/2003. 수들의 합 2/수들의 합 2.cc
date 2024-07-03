#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[10'002];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	int en = 0;
	int sum = a[0];
	for (int st = 0; st < N; ++st)
	{
		while (en < N && sum < M)
		{
			++en;
			if (en != N)
				sum += a[en];
		}

		if (sum == M)
			++ans;
		sum -= a[st];
	}
	cout << ans;
}