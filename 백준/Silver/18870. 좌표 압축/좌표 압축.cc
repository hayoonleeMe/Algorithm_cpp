#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1'000'005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	vector<int> sorted_v(arr, arr + N);
	sort(sorted_v.begin(), sorted_v.end());
	sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

	for (int i = 0; i < N; ++i)
	{
		cout << lower_bound(sorted_v.begin(), sorted_v.end(), arr[i]) - sorted_v.begin() << ' ';
	}
}