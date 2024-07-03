#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N;
unordered_map<string, unordered_set<string>> R;

bool IsHerited(const string& parent, const string& target)
{
	if (R.find(parent) != R.end())
	{
		unordered_set<string>& childs = R[parent];
		if (childs.find(target) != childs.end())
		{
			return true;
		}

		for (const string& child : childs)
		{
			if (IsHerited(child, target))
				return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	while (N--)
	{
		string A, B;
		cin >> A >> B;

		if (N > 0)
		{
			R[B].insert(A);
		}
		else
		{
			if (IsHerited(B, A))
				cout << 1;
			else
				cout << IsHerited(A, B);
		}
	}
	
}