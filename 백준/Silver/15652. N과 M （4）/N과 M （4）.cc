#include <bits/stdc++.h>
using namespace std;

int N, M;
int seq[10];

void func(int cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; ++i)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{ 
		if (cur > 0 && seq[cur - 1] > i)
			continue;

		seq[cur] = i;
		func(cur + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	func(0);
}