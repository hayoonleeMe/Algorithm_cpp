#include <bits/stdc++.h>
using namespace std;

int N;
int U[1002];
vector<int> two;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> U[i];
	sort(U, U + N);
	
	for (int x = 0; x < N; ++x)
		for (int y = x; y < N; ++y)
			two.push_back(U[x] + U[y]);
	sort(two.begin(), two.end());	

	for (int k = N - 1; k > 0; --k)
	{
		for (int z = 0; z < k; ++z)
		{
			if (binary_search(two.begin(), two.end(), U[k] - U[z]))
			{
				cout << U[k];
				return 0;
			}
		}
	}
}
