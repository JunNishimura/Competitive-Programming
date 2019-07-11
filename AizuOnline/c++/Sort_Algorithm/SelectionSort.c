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

void SelectionSort(int a[], int n) 
{
    int i, j, min;
    for (i = 0; i < n-1; ++i) 
    {
        min = i;
        for (j = i; j < n; ++j) 
        {
            if (a[min] > a[j]) min = j;
        }
        if (min != i) 
        {
            swap(a, i, min);
            ++swap_cnt;
            print_array(a, n);
        } 
    }
}

int main() 
{
    int a[] = {1,4,6,3,7,2,8,5,9,10}; // random element
    int b[] = {1,2,3,4,5,6,7,8,9,10}; // best case
    int c[] = {10,1,2,3,4,5,6,7,8,9}; // worst case 
    int d[] = {2,3,4,5,6,7,8,9,10,1}; // worst case2
    int n = 10;

    SelectionSort(d, n);
    print_array(d, n);

    printf("swap count: %d\n", swap_cnt);
}