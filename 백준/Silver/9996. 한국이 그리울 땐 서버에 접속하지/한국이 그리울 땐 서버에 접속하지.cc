#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> pattern;

	int starPos = pattern.find('*');
	string subBeforeStar = pattern.substr(0, starPos);
	string subAfterStar = pattern.substr(starPos + 1, pattern.size() - starPos - 1);

	while (N--)
	{
		string str;
		cin >> str;

		if (str.find(subBeforeStar) != 0 || str.find(subAfterStar, str.size() - subAfterStar.size()) == -1 || subBeforeStar.size() + subAfterStar.size() > str.size())
			cout << "NE\n";
		else
			cout << "DA\n";
	}
}