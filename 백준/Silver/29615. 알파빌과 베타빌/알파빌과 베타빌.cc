#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1002];
int fr[1002];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < M; ++i)
		cin >> fr[i];

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i] == fr[j])
				++ans;
		}
	}
	cout << M - ans;
}