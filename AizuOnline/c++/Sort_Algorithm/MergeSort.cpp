#include <iostream> 
#define N 100
#define INF 2000000000
using namespace std;
int L[N], R[N];

int cnt(0);

void MergeSort(int array[], int left, int mid, int right) 
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; ++i) L[i] = array[left+i];
    for (int i = 0; i < n2; ++i) R[i] = array[mid+i];
    L[n1] = R[n2] = INF;
    int l = 0; 
    int r = 0;
    for (int i = left; i < right; ++i)
    {
        ++cnt;
        if (L[l] <= R[r]) array[i] = L[l++];
        else array[i] = R[r++];
    }
}

void Merge(int left, int right, int array[]) 
{
    if (left + 1 < right) 
    {
        int mid = (left + right) / 2;
        Merge(left, mid, array);
        Merge(mid, right, array);
        MergeSort(array, left, mid, right);
    }
}

int main() 
{
    // int array[] = {3,4,1,5,6,8,2,10,9,7};
    int array[] = {10,9,8,7,6,5,4,3,2,1}; // worst case 

    Merge(0, 10, array);
    for (int i = 0; i < 10; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << "count : " << cnt << endl;
}