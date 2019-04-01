#include <iostream>
#include <stdio.h>
using namespace std;

int cnt = 0;
void InsertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void ShellSort(int A[], int n)
{
    int m, l=1, G[100];
    while (l <= n)
    {
        G[m] = l;
        l = 3*l+1;
        m++;
    }
    for (int i = 0; i < m/2; i++) swap(G[i], G[m-(i+1)]);
    for (int i = 0; i < m; i++) InsertionSort(A, n, G[i]);
    printf("%d\n", m);
    for (int i = 0; i < m; i++) printf("%d ", G[i]);
    printf("\n%d\n", cnt);
}

int main() 
{
    int n;
    int A[1000000];
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    ShellSort(A, n);
    for (int i = 0; i < n; i++) printf("%d\n", A[i]);
}