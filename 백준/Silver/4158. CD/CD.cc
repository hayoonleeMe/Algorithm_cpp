#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1'000'002];
int b[1'000'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			return 0;

		for (int i = 0; i < N; ++i)
			cin >> a[i];
		for (int i = 0; i < M; ++i)
			cin >> b[i];

		int ans = 0;
		for (int i = 0; i < N; ++i)
			if (binary_search(b, b + M, a[i]))
				++ans;
		cout << ans << '\n';
	}
}