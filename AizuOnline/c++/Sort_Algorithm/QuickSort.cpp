#include <iostream>
#define MAX 100
using namespace std;

int Partition(int Arr[], int left, int t_id) 
{
    int target = Arr[t_id];
    int j = left-1;
    for (int i = left; i < t_id; ++i) 
    {
        if (Arr[i] <= target) swap(Arr[++j], Arr[i]);
    }
    ++j;
    swap(Arr[j], Arr[t_id]);
    return j;
}

void QuickSort(int Arr[], int left, int right) 
{
    if (right < left) return;
    int ret_part = Partition(Arr, left, right);
    QuickSort(Arr, left, ret_part-1);
    QuickSort(Arr, ret_part+1, right);
}

int main() 
{
    int a_num, Arr[MAX];
    scanf("%d", &a_num);
    for (int i = 0; i < a_num; ++i) scanf("%d", &Arr[i]);
    // execute insertion sort
    QuickSort(Arr, 0, a_num-1);
    // show sorted array
    for (int i = 0; i < a_num; ++i) printf("%d ", Arr[i]);
    printf("\n");
}