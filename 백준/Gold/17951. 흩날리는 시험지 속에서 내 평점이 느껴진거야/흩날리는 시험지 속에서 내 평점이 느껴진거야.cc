#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[100'002];
int total;

bool Solve(int mid)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += a[i];

		if (sum >= mid)
		{
			++cnt;
			sum = 0;
		}
	}
	return cnt >= K;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		total += a[i];
	}

	int st = 0;
	int en = total;
	while (st < en)
	{
		int mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}

//8 3
//12 7 19 20 17 14 9 10
//
//12 19 38 58 75 89 98 108
//
//parametric.....................
//
//문제 개수의 합 최소를 찾음
//합 최소 커지면 생성 가능 그룹 수 줄어듬
//		작아지면 생성 가능 그룹 수 늘어남