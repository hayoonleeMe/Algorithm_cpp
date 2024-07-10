#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[1000'005];
vector<pair<int, int>> v;
long long ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);

	v.push_back({ arr[0].first, arr[0].second });
	for (int i = 1; i < N; ++i)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		bool processed = false;
		for (int j = 0; j < v.size(); ++j)
		{
			int px = v[j].first;
			int py = v[j].second;

			// full in ... p.x - x - y - p.y
			if (px <= x && y <= py)
			{
				processed = true;
				break;
			}

			// partially in ... p.x - x - p.y - y or x - p.x - y - p.y
			if (px <= x && x <= py)
			{
				v[j].second = y;
				processed = true;
				break;
			}
			else if (px <= y && y <= py)
			{
				v[j].first = x;
				processed = true;
				break;
			}
		}

		// out p.x - p.y - x - y]
		if (!processed)
			v.push_back({ x, y });
	}

	for (auto p : v)
		ans += (p.second - p.first);
	cout << ans;
}