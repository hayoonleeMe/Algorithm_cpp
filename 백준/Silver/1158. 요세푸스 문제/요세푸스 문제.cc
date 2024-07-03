#include <bits/stdc++.h>
using namespace std;

int N, K;
list<int> seq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		seq.push_back(i);

	list<int>::iterator c = seq.begin();
	cout << "<";
	while (seq.size() > 1)
	{
		for (int j = 0; j < K - 1; ++j)
		{
			++c;
			if (c == seq.end())
				c = seq.begin();
		}

		cout << *c << ", ";
		c = seq.erase(c);
		if (c == seq.end())
			c = seq.begin();
	}
	cout << *c << ">";
}