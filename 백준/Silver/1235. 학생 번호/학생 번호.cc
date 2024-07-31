#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int N;
string arr[1002];
int maxLength;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		maxLength = max(maxLength, (int)arr[i].size());
	} 
	
	bool find = false;
	for (int k = 1; k <= maxLength; ++k)
	{
		unordered_set<string> us;

		for (int i = 0; i < N; ++i)
		{
			const string& name = arr[i];
			string sub = name.substr(name.size() - k, k);
			if (us.find(sub) != us.end())
			{
				find = false;
				break;
			}

			us.insert(sub);
			find = true;
		}
		if (find)
		{
			cout << k;
			return 0;
		}
	}
}