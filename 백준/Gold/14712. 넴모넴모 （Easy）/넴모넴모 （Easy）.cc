#include <bits/stdc++.h>
using namespace std;

int N, M;
bool a[30][30];
int ans;

bool Nemo(int i, int j)
{
	bool inRange = i - 1 >= 0 && j - 1 >= 0;
	return inRange && a[i - 1][j] && a[i][j - 1] && a[i - 1][j - 1];
}

void func(int i, int j)
{
	if (i == N - 1 && j == M)
	{
		++ans;
		return;
	}

	if (j == M)
	{
		j = 0;
		++i;
	}

	a[i][j] = 1;
	if (!Nemo(i, j))
		func(i, j + 1);
	a[i][j] = 0;
	func(i, j + 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	func(0, 0);
	cout << ans;
}