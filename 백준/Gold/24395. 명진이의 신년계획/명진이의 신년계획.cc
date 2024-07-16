#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int R[102];
int B[102];
int D[102];

int d[52][52];
pair<int, int> ans[100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> R[i] >> B[i] >> D[i];

	for (int i = 0; i <= 50; ++i)
		fill(d[i], d[i] + 51, -1);
	d[0][0] = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 50; j >= 0; --j)
		{
			for (int k = 50; k >= 0; --k)
			{
				if (j >= R[i] && k >= B[i] && d[j - R[i]][k - B[i]] != -1)
					d[j][k] = max(d[j][k], d[j - R[i]][k - B[i]] + D[i]);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		int a, b;
		cin >> a >> b;

		ans[i].X = d[a][b] != -1 ? d[a][b] : 0;
		ans[i].Y = i;
	}
	sort(ans, ans + N + 1);

	for (int i = 1; i <= N; ++i)
		cout << ans[i].Y << ' ' << ans[i].X << '\n';
}