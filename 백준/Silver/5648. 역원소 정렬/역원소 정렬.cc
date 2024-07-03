#include <bits/stdc++.h>
using namespace std;

int N; 
vector<long long> arr;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		long long n;
		cin >> n;
		for (; n % 10 == 0; n /= 10);
		string s = to_string(n);
		reverse(s.begin(), s.end());
		arr.push_back(stoll(s));
	}

	sort(arr.begin(), arr.end());
	for (long long n : arr)
		cout << n << '\n';
}