#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A[100001] = { 0, };
    
    int N;
    cin >> N;
    for (int i = 1; i<= N; ++i)
    {
        int n;
        cin >> n;
        A[i] = n;
    }
    sort(A + 1, A + N + 1);
    
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int n;
        cin >> n;
        
        if (binary_search(A + 1, A + N + 1, n))
            cout << "1\n";
        else
            cout << "0\n";
    }
    
}