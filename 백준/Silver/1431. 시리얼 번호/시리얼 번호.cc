#include <bits/stdc++.h>
using namespace std;

int N;
string arr[52];

bool cmp(const string& a, const string& b)
{
	if (a.size() != b.size()) 
		return a.size() < b.size();
	else
	{
		int na = 0;
		for (char c : a)
			if (isdigit(c))
				na += int(c - '0');

		int nb = 0;
		for (char c : b)
			if (isdigit(c))
				nb += int(c - '0');

		if (na != nb)
			return na < nb;
		else
			return a < b;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; ++i)
		cout << arr[i] << '\n';
}