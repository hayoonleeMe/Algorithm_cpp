#include <bits/stdc++.h>
using namespace std;

int N;
int p[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	sort(p, p + N);

	int sum = 0;
	for (int i = 0; i < N; ++i)
		sum += p[i] * (N - i);

	cout << sum;
}