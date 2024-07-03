#include <bits/stdc++.h>
using namespace std;

int M, N;
int snack[1'000'005];

bool Solve(int x)
{
	int num = 0;
	for (int length : snack)
	{
		num += length / x;
	}
	return num >= M;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		cin >> snack[i];

	int st = 1;
	int en = *max_element(snack, snack+N);
	while (st < en)
	{
		int mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	if (Solve(st))
		cout << st;
	else
		cout << 0;
}