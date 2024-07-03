#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[12];
bool isused[12];
vector<int> v;
map<string, bool> m;

void func(int k)
{
	if (k == K)
	{	
		string s;
		for (int i = 0; i < K; ++i)
			s += to_string(v[i]);
		m[s] = 1;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (isused[i])
			continue;

		isused[i] = 1;
		v.push_back(a[i]);
		func(k + 1);
		v.pop_back();
		isused[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	func(0);
	cout << m.size();
}