#include <iostream>
#define MAX 100
using namespace std;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n-1; ++i) 
    {
        for (int j = n-1; i < j; --j) 
        {
            if (A[j] < A[j-1]) swap(A[j], A[j-1]);
        }
    }
}

int main() 
{
    int n, A[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    // execute selection sort
    BubbleSort(A, n);
    // show sorted array
    for (int i = 0; i < n; ++i) printf("%d ", A[i]);
    printf("\n");
}