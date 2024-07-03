#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, string> m;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (N--)
	{
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}

	while (M--)
	{
		string s;
		cin >> s;
		cout << m[s] << '\n';
	}
}