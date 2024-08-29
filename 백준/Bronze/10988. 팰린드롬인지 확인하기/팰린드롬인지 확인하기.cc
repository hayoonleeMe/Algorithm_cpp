#include <bits/stdc++.h>
using namespace std;

string s, temp;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
	temp = s;
	reverse(temp.begin(), temp.end());
	cout << (temp == s);
}