#include <bits/stdc++.h>
using namespace std;

int N, K, temp, ret = -10000004;
int psum[100'004];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = K; i <= N; ++i)
		ret = max(ret, psum[i] - psum[i - K]);

	cout << ret;
}