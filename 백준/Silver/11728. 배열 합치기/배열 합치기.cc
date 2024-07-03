#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1000002], B[1000002], C[2000004];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i)
		cin >> B[i];

	int a = 0, b = 0;
	for (int i = 0; i < N + M; ++i)
	{
		if (a == N)
			C[i] = B[b++];
		else if (b == M)
			C[i] = A[a++];
		else if (A[a] < B[b])
			C[i] = A[a++];
		else
			C[i] = B[b++];
	}

	for (int i = 0; i < N + M; ++i)
		cout << C[i] << ' ';
}