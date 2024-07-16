#include <bits/stdc++.h>
using namespace std;

int N, M;
string s[100'002];
int p[100'002];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> s[i] >> p[i];

	for (int i = 0; i < M; ++i)
	{
		int pp;
		cin >> pp;

		int index = upper_bound(p, p + N + 1, pp - 1) - p;
		if (index >= N)
			index = N - 1;

		cout << s[index] << '\n';
	}
}

