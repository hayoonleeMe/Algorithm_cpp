#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;	
	cin >> n;

	while (n--)
	{
		int m;
		cin >> m;

		vector<int> v;
		vector<int> left;
		for (int i = 0; i < 2 * m; ++i)
		{
			int t;
			cin >> t;
			v.push_back(t);
			if (i < m)
				left.push_back(t);
		}
		sort(v.begin(), v.end());

		int ans = 0;
		for (int n : left)
		{
			if (!binary_search(v.begin(), v.end(), n))
				continue;
			if (!binary_search(v.begin(), v.end(), n + 500))
				continue;
			if (!binary_search(v.begin(), v.end(), n + 1000))
				continue;
			if (!binary_search(v.begin(), v.end(), n + 1500))
				continue;
			++ans;
		}
		cout << ans << '\n';
	}
}