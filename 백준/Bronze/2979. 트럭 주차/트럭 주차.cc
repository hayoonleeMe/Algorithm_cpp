#include <bits/stdc++.h>
using namespace std;

int A, B, C, sum;
int t[103];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;
	for (int i = 0; i < 3; ++i)
	{
		int st, en;
		cin >> st >> en;
		for (int i = st; i <= en - 1; ++i)
			t[i]++;
	}

	for (int i = 1; i <= 100; ++i)
	{
		if (t[i] == 1)
			sum += A;
		else if (t[i] == 2)
			sum += 2 * B;
		else if (t[i] == 3)
			sum += 3 * C;
	}
	cout << sum;
}