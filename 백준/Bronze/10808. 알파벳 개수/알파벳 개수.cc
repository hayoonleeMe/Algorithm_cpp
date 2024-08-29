#include <bits/stdc++.h>
using namespace std;

int alp[30];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	for (char c : s)
		alp[int(c - 'a')]++;
	for (int i = 0; i < 26; ++i)
		cout << alp[i] << ' ';
}