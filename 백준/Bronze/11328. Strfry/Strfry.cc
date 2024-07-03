#include <bits/stdc++.h>
using namespace std;

int N;
int arr1[26];
int arr2[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));

		string s1, s2;
		cin >> s1 >> s2;

		if (s1.size() != s2.size())
		{
			cout << "Impossible\n";
			continue;
		}

		for (char c : s1)
			++arr1[c - 'a'];

		for (char c : s2)
			++arr2[c - 'a'];

		bool isPossible = true;
		for (char c : s2)
		{
			if (arr2[c - 'a'] != arr1[c - 'a'])
			{
				cout << "Impossible\n";
				isPossible = false;
				break;
			}
		}

		if (isPossible)
			cout << "Possible\n";
	}
}