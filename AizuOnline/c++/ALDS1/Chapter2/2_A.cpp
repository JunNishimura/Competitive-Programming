#include <iostream>
using namespace std;

int main()
{
    int n, A[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int i, j = 0, c = 0;
    while (j != n-1)
    {
        i = n-1;
        while (i > j)
        {
            if (A[i] < A[i-1]) 
            {
                 swap(A[i], A[i-1]);
                 c++;
            }
            i--;
        }
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i==n-1) printf("%d\n%d\n", A[i], c);
        else printf("%d ", A[i]);
    }
}