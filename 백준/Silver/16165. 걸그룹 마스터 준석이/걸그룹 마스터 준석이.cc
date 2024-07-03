#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, vector<string>> teamToMember;
unordered_map<string, string> memberToTeam;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (N--)
	{
		string team;
		int memberNum;
		cin >> team >> memberNum;
		string member;
		while (memberNum--)
		{
			cin >> member;
			teamToMember[team].push_back(member);
			memberToTeam[member] = team;
		}
		vector<string>& v = teamToMember[team];
		sort(v.begin(), v.end());
	}

	while (M--)
	{
		string str;
		int x;
		cin >> str >> x;
		if (x)
			cout << memberToTeam[str] << '\n';
		else
		{
			vector<string>& v = teamToMember[str];
			for (int i = 0; i < v.size(); ++i)
				cout << v[i] << '\n';
		}
	}
}