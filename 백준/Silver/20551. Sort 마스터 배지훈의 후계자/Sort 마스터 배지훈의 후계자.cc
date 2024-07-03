#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[200'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A, A + N);

	while (M--)
	{
		int D; cin >> D;

		int pos = lower_bound(A, A + N, D) - A;
		if (binary_search(A, A+N, D) && pos < N)
			cout << pos << '\n';
		else
			cout << -1 << '\n';
	}
}
