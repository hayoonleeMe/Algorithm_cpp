#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long N;
int P, Q;
unordered_map<long long, long long> um;

long long Solve(long long x)
{
	if (x == 0)
		return 1;
	if (um[x])
		return um[x];

	um[x] = Solve(x / P) + Solve(x / Q);
	return um[x];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> P >> Q;
	cout << Solve(N);
}