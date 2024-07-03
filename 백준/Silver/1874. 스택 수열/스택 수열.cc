#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string result = "";
	vector<int> num;
	queue<int> sequence;
	for (int i = 1; i <= N; ++i)
	{
		int n;
		cin >> n;
		sequence.push(n);
		num.push_back(i);
	}

	stack<int> s;
	int validNumIndex = 0;
	while (!sequence.empty())
	{
		int n = sequence.front();
		sequence.pop();

		for (int i = validNumIndex; i < N; ++i)
		{
			int a = num[i];

			if (a > n)
				break;

			s.push(num[i]);
			result += "+\n";
			++validNumIndex;
		}

		// 스택의 top이 n
		if (n == s.top())
		{
			s.pop();
			result += "-\n";
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << result;
}