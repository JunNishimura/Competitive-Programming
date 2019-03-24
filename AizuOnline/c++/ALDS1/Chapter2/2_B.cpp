#include <iostream>
using namespace std;

int main() 
{
    int n, A[101], c=0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int t = 0; // target index
    while (t < n)
    {
        int minI = t;
        for (int i = t+1; i < n; i++)
        {
            if (A[minI] > A[i]) minI = i;
        }
        if (minI != t) swap(A[t], A[minI]), c++;
        t++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n-1) printf("%d ", A[i]);
        else printf("%d\n%d\n", A[i], c);
    }
}