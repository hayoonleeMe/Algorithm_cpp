#include <bits/stdc++.h>
using namespace std;

int N, M, target;
int a[500'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	
	cin >> M;
	while (M--)
	{
		cin >> target;
		cout << binary_search(a, a + N, target) << ' ';
	}
}