#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 14;
bool isused1[2 * MAX + 2];
bool isused2[2 * MAX + 2];
bool isused3[2 * MAX + 2];

int cnt = 0;
void func(int cur)
{
	if (cur == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + N - 1])
			continue;

		isused1[i] = 1;
		isused2[cur + i] = 1;
		isused3[cur - i + N - 1] = 1;

		func(cur + 1);

		isused1[i] = 0;
		isused2[cur + i] = 0;
		isused3[cur - i + N - 1] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	func(0);

	cout << cnt;
}