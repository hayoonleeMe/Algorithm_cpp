#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> a[1002];
int d[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		a[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (const int pre : a[i])
			d[i] = max(d[i], d[pre]);
		d[i] += 1;
	}

	for (int i = 1; i <= N; ++i)
		cout << d[i] << ' ';
}