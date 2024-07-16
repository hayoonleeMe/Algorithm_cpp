#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[500'002];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int en = 0;
	long long tot = 0;
	for (int st = 0; st < N; ++st)
	{
		if (st > en)
			en = st;
		while (en < N && tot + arr[en] <= M)
		{
			tot += arr[en];
			++en;
		}
		ans = max(ans, tot);
		if (st < en)
			tot -= arr[st];

		if (en == N)
			break;
	}
	cout << ans;
}
