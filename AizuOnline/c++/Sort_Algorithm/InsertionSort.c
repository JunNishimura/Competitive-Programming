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

void InsertionSort(int a[], int n) 
{
    int i, j;

    for (i = 1; i < n; ++i) 
    {
        for (j = i; j > 0 && a[j] < a[j-1]; --j) 
        {
            swap(a, j, j-1);
            ++swap_cnt;
            print_array(a, n);
        }
    }
}

int main() 
{
    int a[] = {1,4,6,3,7,2,8,5,9,10}; // random element
    int b[] = {1,2,3,4,5,6,7,8,9,10}; // best case
    int c[] = {10,9,8,7,6,5,4,3,2,1}; // worst case 
    int d[] = {9,8,7,6,5,4,3,2,1,10};
    int n = 10;

    InsertionSort(d, n);
    print_array(d, n);

    printf("swap count: %d\n", swap_cnt);
}