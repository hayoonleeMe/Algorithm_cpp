#include <bits/stdc++.h>
using namespace std;

int N, K;
int pAns[22];
int t[22];
bool used[22];

int ans;

void Solve(int k)
{
    // 최대값 갱신
    int count = 0;
    for (int i = 0; i < N; ++i)
        count += pAns[i] == t[i];
    ans = max(ans, count);

    if (k == K)
        return;

    for (int p = 0; p < N; ++p)
    {
        if (used[p])
            continue;

        used[p] = 1;

        vector<int> buffer(t, t + N);
        
        // 밀기
        for (int i = N - 1; i > p; --i)
            t[i] = t[i - 1];
        t[p] = 0;

        Solve(k + 1);

        for (int i = p; i < N; ++i)
            t[i] = buffer[i];

        // 당기기
        for (int i = p; i < N; ++i)
            t[i] = t[i + 1];
        t[N - 1] = 0;

        Solve(k + 1);

        for (int i = p; i < N; ++i)
            t[i] = buffer[i];

        used[p] = 0;
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> pAns[i];
    for (int i = 0; i < N; ++i)
        cin >> t[i];

    Solve(0);

    cout << ans;
}