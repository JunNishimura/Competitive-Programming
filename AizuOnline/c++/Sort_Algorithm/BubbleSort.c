#include <stdio.h> 
#include <stdlib.h> 

int swap_cnt = 0;

void print_array(int a[], int n) 
{
    int i;
    for (i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

void swap(int a[], int i, int j) 
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void BubbleSort(int a[], int n) 
{
    int i, j;

    for (i = 0; i < n-1; ++i) 
    {
        for (j = n-1; j > i; --j) 
        {
            if (a[j] < a[j-1])
            {
                swap(a, j, j-1);
                ++swap_cnt;
            }
        }
        print_array(a, n);
    }
}

int main() 
{
    int a[] = {1,4,6,3,7,2,8,5,9,10}; // random element
    int b[] = {1,2,3,4,5,6,7,8,9,10}; // best case
    int c[] = {10,9,8,7,6,5,4,3,2,1}; // worst case
    int n = 10;

    BubbleSort(c, n);

    printf("swap count: %d\n", swap_cnt);
}