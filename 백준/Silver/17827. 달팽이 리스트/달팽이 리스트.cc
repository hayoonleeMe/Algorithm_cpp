#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int arr[200'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	int t = N - V + 1;

	int k, ans;
	while (M--)
	{
		cin >> k;

		int cur = k;
		if (cur < N)
			ans = arr[cur + 1];
		else
		{
			cur -= N;
			cur = cur % t + V;
			ans = arr[cur];
		}

		cout << ans << '\n';
	}
}

