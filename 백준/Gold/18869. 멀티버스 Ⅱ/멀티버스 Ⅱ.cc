#include <bits/stdc++.h>
using namespace std;

int M, N;
int a[102][10'002];
int ans;

void Compress(int t[])
{
	vector<int> temp(t, t + N);
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	for (int i = 0; i < N; ++i)
		t[i] = lower_bound(temp.begin(), temp.end(), t[i]) - temp.begin();
}

bool Check(int A[], int B[])
{
	for (int i = 0; i < N; ++i)
		if (A[i] != B[i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> a[i][j];
		Compress(a[i]);
	}

	for (int i = 0; i < M - 1; ++i)
		for (int j = i + 1; j < M; ++j)
			ans += Check(a[i], a[j]);

	cout << ans;
}