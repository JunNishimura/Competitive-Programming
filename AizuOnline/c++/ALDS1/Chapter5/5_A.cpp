#include <iostream>
#include <stdio.h>
using namespace std;

int A[25], n;

bool Solve(int i, int m) 
{
    printf("Solve(%d, %d)\n", i, m);
    if (m == 0) return true;
    if (i == n) return false;
    int res = Solve(i+1, m) || Solve(i+1, m-A[i]);
    return res;
}

int main() {
    int q, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    } 
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        if (Solve(0, t)) printf("yes\n");
        else printf("no\n");
    }
}