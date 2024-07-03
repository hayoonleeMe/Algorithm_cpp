#include <bits/stdc++.h>
using namespace std;

int N, K, w, v;
// W, V
int W[102], V[102];
// d[i] : 물품의 개수가 i개일 때 최대 가치합
int d[102][100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> w >> v;
		W[i] = w;
		V[i] = v;
	}

	for (int k = 1; k <= K; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			// i번째 물건을 배낭에 못넣을때
			if (W[i] > k)
				d[i][k] = d[i - 1][k];
			else
				// i번째 물건 안넣기 vs 넣기
				d[i][k] = max(d[i - 1][k], V[i] + d[i - 1][k - W[i]]);
		}
	}

	cout << d[N][K];
}