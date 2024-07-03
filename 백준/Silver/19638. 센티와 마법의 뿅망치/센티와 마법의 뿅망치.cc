#include <bits/stdc++.h>
using namespace std;

int N, H, T;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> H >> T;

	int over = 0;
	for (int i = 0; i < N; ++i)
	{
		int n; cin >> n;
		pq.push(n);
		if (n >= H)
			++over;
	}

	if (over == 0)
	{
		cout << "YES\n" << 0;
		return 0;
	}

	int count = 1;
	for (; count <= T; ++count)
	{
		int half = max(1, pq.top() / 2);
		pq.pop();
		pq.push(half);
		if (half < H)
			--over;
		if (over <= 0)
			break;
	}
	if (over <= 0)
		cout << "YES\n" << count;
	else
		cout << "NO\n" << pq.top();
}