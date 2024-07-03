#include <bits/stdc++.h>
using namespace std;

int K;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K;

	while (K--)
	{
		int n;
		cin >> n;

		if (n == 0)
			s.pop();
		else
			s.push(n);
	}

	int sum = 0;
	for (; !s.empty(); s.pop())
		sum += s.top();

	cout << sum;
}