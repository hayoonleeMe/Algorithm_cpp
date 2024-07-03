#include <bits/stdc++.h>
using namespace std;

int N;
// 0 공백 1 좌 2 우
int d[100'002][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	d[1][0] = d[1][1] = d[1][2] = 1;

	for (int i = 2; i <= N; ++i)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
	}

	cout << (d[N][0] + d[N][1] + d[N][2]) % 9901;
}