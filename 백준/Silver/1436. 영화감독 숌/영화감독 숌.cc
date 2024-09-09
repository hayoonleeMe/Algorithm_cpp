#include <iostream>
#include <list>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	/*list<int> nums;
	int cur = 666;
	nums.push_back(cur);
	--N;
	int offset = 1000;
	while (N > 0)
	{
		int i = pow(10, log10(cur));
		if ()
		{

		}
		else
		{
			cur += offset;
			nums.push_back(cur);
			--N;
		}
	}

	cout << nums.back() << '\n';*/

	list<string> nums;
	nums.push_back("666");
	--N;

	int cur = 1666;
	while (N > 0)
	{
		//cout << "N : " << N << " cur : " << cur << '\n';
		string strCur = to_string(cur);
		if (strCur.find("666") != string::npos)
		{
			nums.push_back(strCur);
			--N;
		}

		++cur;
	}

	cout << nums.back() << '\n';
}