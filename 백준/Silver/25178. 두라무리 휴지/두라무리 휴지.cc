#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<char> cond{ 'a', 'e', 'i', 'o', 'u' };

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	string str1, str2;
	cin >> N >> str1 >> str2;

	unordered_map<char, int> um1{};
	unordered_map<char, int> um2{};

	for (int i = 0; i < N; ++i)
	{
		if (um1.find(str1[i]) != um1.end())
			um1[str1[i]]++;
		else
			um1[str1[i]] = 1;

		if (um2.find(str2[i]) != um2.end())
			um2[str2[i]]++;
		else
			um2[str2[i]] = 1;
	}

	if (um1 != um2)
	{
		cout << "NO";
		return 0;
	}

	if (str1[0] != str2[0] || str1[N - 1] != str2[N - 1])
	{
		cout << "NO";
		return 0;
	}

	for (char c : cond)
	{
		while (str1.find(c) != -1)
			str1.erase(str1.find(c), 1);
		while (str2.find(c) != -1)
			str2.erase(str2.find(c), 1);
	}

	if (str1 != str2)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES";
}