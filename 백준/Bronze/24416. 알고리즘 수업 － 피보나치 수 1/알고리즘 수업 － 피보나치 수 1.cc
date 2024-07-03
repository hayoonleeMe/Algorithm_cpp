#include <bits/stdc++.h>
using namespace std;

int C1, C2;
int f[45];

int fib(int n) {
    if (n == 1 or n == 2)
    {
        ++C1;
        return 1;  // 코드1
    }
    else
        return (fib(n - 1) + fib(n - 2));
}

void fibonacci(int n) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        ++C2;
        f[i] = f[i - 1] + f[i - 2]; // 코드2
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    fib(n);
    fibonacci(n);

    cout << C1 << ' ' << C2;
}