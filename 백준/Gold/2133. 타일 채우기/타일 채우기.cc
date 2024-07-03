#include <bits/stdc++.h>
using namespace std;

int N;
int d[35];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	d[0] = 1;
	d[2] = 3;

	for (int i = 4; i <= N; i += 2)
	{
		d[i] += d[i - 2] * d[2];
		for (int j = i - 4; j >= 0; j -= 2)
			d[i] += d[j] * 2;
	}
	
	cout << d[N];
}