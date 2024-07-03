#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<long long> v;
int ans = -1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		int s, ii, c;
		cin >> s >> ii >> c;
		for (int j = 1; j <= c; ++j)
			v.push_back(s + (j - 1) * ii);
	}
	sort(v.begin(), v.end());

	int t = lower_bound(v.begin(), v.end(), T) - v.begin();
	if (t < v.size())
		ans = v[t] - T;
	cout << ans;
}