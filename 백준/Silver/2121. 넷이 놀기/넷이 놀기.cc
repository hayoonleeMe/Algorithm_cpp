#include <bits/stdc++.h>
using namespace std;

int N, A, B, a, b;
pair<int, int> arr[500'002];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; ++i)
	{
		int oA = arr[i].first;
		int oB = arr[i].second;

		if (binary_search(arr, arr + N, make_pair(oA + A, oB )) && binary_search(arr, arr + N, make_pair(oA, oB + B)) && binary_search(arr, arr + N, make_pair(oA + A, oB + B)))
			++ans;
	}
	cout << ans;
}