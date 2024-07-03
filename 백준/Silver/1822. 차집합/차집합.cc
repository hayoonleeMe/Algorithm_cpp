#include <bits/stdc++.h>
using namespace std;

int nA, nB;
int A[500'002];
int B[500'002];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> nA >> nB;
	for (int i = 0; i < nA; ++i)
		cin >> A[i];
	sort(A, A + nA);
	for (int i = 0; i < nB; ++i)
		cin >> B[i];
	sort(B, B + nB);

	for (int i = 0; i < nA; ++i)
		if (!binary_search(B, B + nB, A[i]))
			ans.push_back(A[i]);

	if (ans.size() > 0)
	{
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << ' ';
	}
	else
		cout << 0;
}