#include <stdio.h>
#include <stdlib.h>

int swap_cnt = 0;

void print_array(int a[], int n) 
{
    int i;
    for (i = 0; i < n; ++i) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int i, int j) 
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int Partition(int a[], int left, int pivot) 
{
    int i = left, j;
    for (j = left; j < pivot; ++j)
    {
        ++swap_cnt;
        if (a[pivot] > a[j])
        {
            swap(a, i++, j);
        }
    }
    swap(a, i, pivot);
    return i;
}

void QuickSort(int a[], int left, int right) 
{
    int p;
    if (left < right) 
    {
        p = Partition(a, left, right);
        QuickSort(a, left, p-1);
        QuickSort(a, p+1, right);
    }
}

int main() 
{
    int a[] = {1,4,10,3,7,2,8,5,9,6};
    int b[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    
    QuickSort(a, 0, n-1);
    print_array(a, n);

    printf("swap count: %d\n", swap_cnt);
}