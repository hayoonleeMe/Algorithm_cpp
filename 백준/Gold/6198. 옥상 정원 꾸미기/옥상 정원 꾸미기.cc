#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> s;
long long c;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int h;
	while (N--)
	{
		cin >> h;

		while (!s.empty() && h >= s.top())
			s.pop();
		c += s.size();
		s.push(h);
	}

	cout << c;
}