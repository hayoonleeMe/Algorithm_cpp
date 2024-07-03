#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[200'004];
int cnt[100'004];
int mx;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	a[N] = 100'001;
	cnt[a[N]] = 0x7f7f7f7f;

	int en = 0;
	++cnt[a[0]];
	for (int st = 0; st < N; ++st)
	{
		while (en < N && cnt[a[en + 1]] + 1 <= K)
		{
			++en;
			if (en != N)
				++cnt[a[en]];
		}
		if (en == N)
			break;

		mx = max(mx, en - st + 1);
		--cnt[a[st]];
	}
	cout << mx;
}