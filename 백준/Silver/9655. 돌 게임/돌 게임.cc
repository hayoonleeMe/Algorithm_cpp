#include <bits/stdc++.h>
using namespace std;

const int SK = 0;
const int CY = 1;
int N;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int turn = SK;
	while (1)
	{
		if (N >= 3)
			N -= 3;
		else
			N -= 1;

		if (N == 0)
		{
			if (turn == SK)
				cout << "SK";
			else
				cout << "CY";
			break;
		}

		turn = (turn + 1) % 2;
	}
}