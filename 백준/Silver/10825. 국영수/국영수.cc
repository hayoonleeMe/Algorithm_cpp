#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<string, int, int, int>> v;

bool cmp(const tuple<string, int, int, int>& x, const tuple<string, int, int, int>& y)
{
	string xn, yn;
	int xa, xb, xc, ya, yb, yc;
	tie(xn, xa, xb, xc) = x;
	tie(yn, ya, yb, yc) = y;

	if (xa != ya)
		return xa > ya;
	if (xb != yb)
		return xb < yb;
	if (xc != yc)
		return xc > yc;
	return xn < yn;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		v.push_back({ s, a, b, c });
	}

	sort(v.begin(), v.end(), cmp);
	for (auto t : v)
	{
		cout << get<0>(t) << '\n';
	}
}