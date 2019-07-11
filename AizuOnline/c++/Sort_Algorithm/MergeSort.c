#include <stdio.h>
#include <stdlib.h> 
#define N 100
int L[N/2+1], R[N/2+1];

int cnt = 0;

void print_array(int a[], int n) 
{
    int i;
    for (i = 0; i < n; ++i) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Merge(int a[], int left, int mid, int right, int n)
{
    int i,j = 0, k = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; ++i) L[i] = a[left+i];
    for (i = 0; i < n2; ++i) R[i] = a[mid+i];
    L[n1] = R[n2] = 2000000000;

    for (i = left; i < right; ++i) 
    {
        if (L[j] <= R[k]) a[i] = L[j++];
        else a[i] = R[k++];
    }
}

void MergeSort(int a[],int left, int right, int n) 
{
    int mid;
    if (left+1 < right) 
    {
        mid = (left + right) / 2;
        MergeSort(a, left, mid, n);
        MergeSort(a, mid, right, n);
        Merge(a, left, mid, right, n);
    }
}

int main() 
{
    int a[] = {1,4,6,3,7,2,8,5,9,10}; // random element
    int n = 10;

    MergeSort(a, 0, n, n);
    print_array(a, n);

    printf("swap cnt: %d\n", cnt);
}