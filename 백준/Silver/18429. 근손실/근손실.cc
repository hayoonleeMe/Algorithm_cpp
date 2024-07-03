#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[10];
vector<int> v;
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		v.push_back(i);
	}

	do
	{
		int w = 500;
		bool can = true;
		for (int i = 0; i < N; ++i)
		{
			w += -K + a[v[i]];
			if (w < 500)
			{
				can = false;
				break;
			}
		}
		if (can)
			++ans;

	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
}