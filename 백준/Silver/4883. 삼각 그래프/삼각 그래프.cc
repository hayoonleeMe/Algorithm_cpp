#include <bits/stdc++.h>
using namespace std;

const int L = 0;
const int M = 1;
const int R = 2;

int N;
int arr[100005][3];
int d[100005][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	// 출발이 가운데이므로 첫 번째 행의 왼쪽을 방문할 수 없음
	d[0][L] = 0x7f7f7f7f;

	int k = 1;
	for (cin >> N; N != 0; cin >> N)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> arr[i][j];

		d[0][M] = arr[0][M];
		d[0][R] = arr[0][M] + arr[0][R];

		for (int i = 1; i < N; ++i)
		{
			d[i][L] = arr[i][L] + min(d[i - 1][L], d[i - 1][M]);
			d[i][M] = arr[i][M] + min({ d[i - 1][L], d[i - 1][M], d[i - 1][R], d[i][L] });
			d[i][R] = arr[i][R] + min({ d[i - 1][M], d[i - 1][R], d[i][M] });
		}

		cout << k++ << ". " << d[N - 1][M] << '\n';
	}
}