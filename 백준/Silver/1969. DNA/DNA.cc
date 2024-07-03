#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> DNAs;
int counts[100];

string ans_DNA;
int ans_HD;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string DNA; cin >> DNA;
		DNAs.push_back(DNA);
	}

	for (int i = 0; i < M; ++i)
	{
		memset(counts, 0, sizeof(counts));

		for (const string& DNA : DNAs)
			counts[(int)DNA[i]] += 1;

		int c = 0;
		int HD = 0;
		for (int j = 0; j < 100; ++j)
		{
			if (counts[j] == 0)
				continue;

			HD += counts[j];
			if (counts[c] < counts[j])
				c = j;
		}

		ans_DNA += (char)c;
		ans_HD += HD - counts[c];
	}

	cout << ans_DNA << '\n' << ans_HD;
}