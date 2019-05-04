#include <iostream>
#define MAX 100
using namespace std;

int L[MAX/2+10], R[MAX/2+10];

void Merge(int Arr[], int left, int middle, int right) 
{
    int num_fhalf = middle - left;
    int num_shalf = right - middle;
    for (int i = 0; i < num_fhalf; ++i) L[i] = Arr[left+i];
    for (int i = 0; i < num_shalf; ++i) R[i] = Arr[middle+i];

    // insert dummy value at the end
    L[num_fhalf] = 10000000;
    R[num_shalf] = 10000000;

    int j = 0, k = 0;
    for (int i = left; i < right; ++i) 
    {
        if (L[j] <= R[k]) Arr[i] = L[j++];
        else Arr[i] = R[k++];
    }
}

// 再帰関数
// 構造： 二つに分けて、前半ソート、後半ソートで合体します。
void MergeSort(int Arr[], int left, int right) 
{
    if (right-left<=1) return;
    int middle = (left + right) / 2;
    MergeSort(Arr, left, middle); // 前半ソート
    MergeSort(Arr, middle, right); // 後半ソート
    Merge(Arr, left, middle, right); // 合体
}

int main() 
{
    int a_num, Arr[MAX];
    scanf("%d", &a_num);
    for (int i = 0; i < a_num; ++i) scanf("%d", &Arr[i]);
    // execute insertion sort
    MergeSort(Arr, 0, a_num);
    // show sorted array
    for (int i = 0; i < a_num; ++i) printf("%d ", Arr[i]);
    printf("\n");
}