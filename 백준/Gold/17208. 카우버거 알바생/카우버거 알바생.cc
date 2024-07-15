#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, K;
pair<int, int> arr[105];
int d[305][305];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].X >> arr[i].Y;

	for (int i = 0; i < N; ++i)
	{
		int im = arr[i].X;
		int ik = arr[i].Y;

		for (int m = M; m >= im; --m)
			for (int k = K; k >= ik; --k)
				d[m][k] = max(d[m][k], d[m - im][k - ik] + 1);
	}

	cout << d[M][K];
}