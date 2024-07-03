#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int a[1'000'002];
int b[1'000'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		sort(a, a + N);

		cin >> M;
		for (int i = 0; i < M; ++i)
			cin >> b[i];

		for (int i = 0; i < M; ++i)
			cout << binary_search(a, a + N, b[i]) << '\n';
	}
}