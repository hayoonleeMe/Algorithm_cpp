#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    d.resize(41);
    d[0] = { 1, 0 };
    d[1] = { 0, 1 };

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;

        for (int i = 2; i <= n; ++i)
            d[i] = { d[i - 1].first + d[i - 2].first, d[i - 1].second + d[i - 2].second };

        cout << d[n].first << ' ' << d[n].second << '\n';
    }
}