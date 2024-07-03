#include <bits/stdc++.h>
using namespace std;

struct tower
{
	int index;
	int height;
};

int N;
int output[500001];
stack<tower> temp;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int h;
		cin >> h;

		if (i == 1)
			temp.push(tower{ i, h });
		else
		{
			while (!temp.empty() && h > temp.top().height)
				temp.pop();

			if (temp.empty())
			{
				temp.push(tower{ i, h });
				continue;
			}

			output[i] = temp.top().index;
			temp.push(tower{ i, h });
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << output[i] << ' ';
}