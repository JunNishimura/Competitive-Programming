#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int A[N+1], B[N];
    for (int i = 0; i < N+1; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];  

    long long total = 0;
    int tmp = 0;
    for (int i = 0; i < N; i++) 
    {
        tmp = min(A[i], B[i]);
        A[i] -= tmp;
        B[i] -= tmp;
        total += tmp;
        tmp = min(A[i+1], B[i]);
        A[i+1] -= tmp;
        B[i] -= tmp;
        total += tmp;
    }
    cout << total << endl;
}