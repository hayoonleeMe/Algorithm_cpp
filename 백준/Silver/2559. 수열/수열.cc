#include <bits/stdc++.h>
using namespace std;

int N, K, sum, cnt;
int a[100'004];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];

		++cnt;
		sum += a[i];

		if (cnt == K)
		{
			v.push_back(sum);
			--cnt;
			sum -= a[i - (K - 1)];
		}
	}
	cout << *max_element(v.begin(), v.end());
}