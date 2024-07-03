#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[20];
char seq[20];

void func(int k, int st, int v, int c)
{
	if (k == L)
	{
		if (v >= 1 && c >= 2)
		{
			for (int i = 0; i < L; ++i)
				cout << seq[i];
			cout << '\n';
		}
		return;
	}

	for (int i = st; i < C; ++i)
	{
		seq[k] = arr[i];
		if (seq[k] == 'a' || seq[k] == 'e' || seq[k] == 'i' || seq[k] == 'o' || seq[k] == 'u')
			func(k + 1, i + 1, v + 1, c);
		else
			func(k + 1, i + 1, v, c + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> arr[i];
	sort(arr, arr + C);

	func(0, 0, 0, 0);
}