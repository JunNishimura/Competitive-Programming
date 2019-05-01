#include <iostream>
#define MAX 100
using namespace std;

void SelectionSort(int* A, int n) 
{
    for (int i = 0; i < n-1; ++i) 
    {
        int min = i;
        for (int j = i+1; j < n; ++j) 
        {
            // find minimum value in the array
            if (A[j] < A[min]) min = j;
        }
        // swap elements
        swap(A[min], A[i]);
    }
}

int main() 
{
    int n, A[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    // execute selection sort
    SelectionSort(A, n);
    // show sorted array
    for (int i = 0; i < n; ++i) printf("%d ", A[i]);
    printf("\n");
}