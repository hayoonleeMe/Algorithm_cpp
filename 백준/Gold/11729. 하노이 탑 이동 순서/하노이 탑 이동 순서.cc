#include <bits/stdc++.h>
using namespace std;

int N;

void func(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}

	func(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	// 1<<N : 2^N (1을 비트 기준 왼쪽으로 N칸 밀으라는 뜻 left shift)
	cout << (1 << N) - 1 << '\n';
	func(1, 3, N);
}