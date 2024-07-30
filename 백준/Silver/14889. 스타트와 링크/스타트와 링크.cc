#include <bits/stdc++.h>
using namespace std;

int N;
int arr[22][22];

int ans = 0x7f7f7f7f7f;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	vector<int> mask;
	mask.resize(N, 1);
	for (int i = 0; i < N / 2; ++i)
		mask[i] = 0;

	do
	{
		vector<int> start, link;
		for (int i = 0; i < mask.size(); ++i)
		{
			if (mask[i] == 0)
				start.push_back(i);
			else
				link.push_back(i);
		}
		
		int startSum = 0;
		for (int i = 0; i < start.size(); ++i)
			for (int j = 0; j < start.size(); ++j)
				startSum += arr[start[i]][start[j]];
		
		int linkSum = 0;
		for (int i = 0; i < link.size(); ++i)
			for (int j = 0; j < link.size(); ++j)
				linkSum += arr[link[i]][link[j]];

		ans = min(ans, abs(startSum - linkSum));

	} while (next_permutation(mask.begin(), mask.end()));

	cout << ans;
}