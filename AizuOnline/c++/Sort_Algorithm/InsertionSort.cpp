#include <iostream>
#define MAX 100
using namespace std;

// Sort by InsertionSort algorithm
void InsertionSort(int Arr[], int a_num) 
{
    for (int i = 0; i < a_num-1; ++i) 
    {
        int tmp = Arr[i+1];
        int j = i;
        while (j >= 0) 
        {
            if (Arr[j] <= tmp) break;
            else swap(Arr[j], Arr[j+1]); 
            j--;
        }
        Arr[j+1] = tmp;
    }
}

int main() 
{   
    int a_num, Arr[MAX];
    scanf("%d", &a_num);
    for (int i = 0; i < a_num; ++i) scanf("%d", &Arr[i]);
    // execute insertion sort
    InsertionSort(Arr, a_num);
    // show sorted array
    for (int i = 0; i < a_num; ++i) printf("%d ", Arr[i]);
    printf("\n");
}