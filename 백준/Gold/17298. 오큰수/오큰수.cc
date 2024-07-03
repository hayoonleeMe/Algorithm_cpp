#include <bits/stdc++.h>
using namespace std;

int N;
int seq[1000001];
int ans[1000001];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> seq[i];

	ans[N] = -1;
	s.push(seq[N]);
	for (int i = N - 1; i > 0; --i)
	{
		while (!s.empty() && seq[i] >= s.top())
			s.pop();

		if (s.empty())
			ans[i] = -1;
		else if (s.top() > seq[i])
			ans[i] = s.top();
		s.push(seq[i]);
	}

	for (int i = 1; i <= N; ++i)
		cout << ans[i] << ' ';
}