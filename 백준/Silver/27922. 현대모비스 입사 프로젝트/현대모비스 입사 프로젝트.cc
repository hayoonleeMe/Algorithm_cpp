#include <bits/stdc++.h>
using namespace std;

int N, K;

int ab[100'002];
int ac[100'002];
int bc[100'002];

int ab_ans, ac_ans, bc_ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		ab[i] = a + b;
		ac[i] = a + c;
		bc[i] = b + c;
	}
	sort(ab, ab + N, greater<>());
	sort(ac, ac + N, greater<>());
	sort(bc, bc + N, greater<>());
	
	for (int i = 0; i < K; ++i)
	{
		ab_ans += ab[i];
		ac_ans += ac[i];
		bc_ans += bc[i];
	}

	cout << max({ ab_ans, ac_ans, bc_ans });
}