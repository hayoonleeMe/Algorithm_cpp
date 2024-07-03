#include <bits/stdc++.h>
using namespace std;

int alpha1[26], alpha2[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (char c : s1)
		++alpha1[c - 'a'];

	for (char c : s2)
		++alpha2[c - 'a'];

	int count = 0;
	for (int i = 0; i < 26; ++i)
		if (alpha1[i] >= alpha2[i])
			count += alpha1[i] - alpha2[i];
	for (int i = 0; i < 26; ++i)
		if (alpha2[i] >= alpha1[i])
			count += alpha2[i] - alpha1[i];

	cout << count;
}