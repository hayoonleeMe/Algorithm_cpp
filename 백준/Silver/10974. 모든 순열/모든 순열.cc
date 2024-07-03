#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; ++i)
		v.push_back(i + 1);

	do
	{
		for (int i = 0; i < N; ++i)
			cout << v[i] << ' ';
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}