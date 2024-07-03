#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	string s = to_string(N);
	for (char c : s)
	{
		int n = c - '0';
		if (n == 6)
		{
			if (arr[6] > arr[9])
				++arr[9];
			else
				++arr[6];
		}
		else if (n == 9)
		{
			if (arr[9] > arr[6])
				++arr[6];
			else
				++arr[9];
		}
		else
			++arr[n];
	}

	cout << *max_element(arr, arr + 10);
}