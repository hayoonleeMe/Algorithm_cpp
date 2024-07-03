#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--)
	{
		string func;
		cin >> func >> N;

		// 문자열에서 숫자 분리
		deque<int> dq;
		string str, seq;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		istringstream ss(str);
		while (getline(ss, seq, ','))
			dq.push_back(stoi(seq));

		bool isFailed = false;
		bool isReversed = false;
		for (char f : func)
		{
			if (f == 'R')
				isReversed = !isReversed;
			else if (f == 'D')
			{
				if (dq.empty())
				{
					isFailed = true;
					break;
				}

				if (isReversed)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		// 출력
		if (dq.empty() && isFailed)
			cout << "error\n";
		else
		{
			cout << '[';

			if (!dq.empty())
			{
				if (isReversed)
					reverse(dq.begin(), dq.end());
				cout << dq.front();
				for (auto it = dq.begin() + 1; it != dq.end(); ++it)
					cout << ',' << *it;
			}
			
			cout << "]\n";
		}
	}
}