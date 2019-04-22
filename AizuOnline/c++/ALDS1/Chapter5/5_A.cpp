#include <iostream>
using namespace std;

int n, q, A[201];
bool exhaustiveSearch(int i, int t) 
{
    if (t == 0) return 1;
    if (i >= n) return 0;
    return exhaustiveSearch(i+1, t) || exhaustiveSearch(i+1, t-A[i]);
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) 
    {
        int k = 0;
        scanf("%d", &k);
        if (exhaustiveSearch(0, k)) printf("yes\n");
        else printf("no\n");
    }
}