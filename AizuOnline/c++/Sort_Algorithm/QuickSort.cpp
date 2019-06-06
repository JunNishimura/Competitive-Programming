#include <iostream> 
#include <vector> 
using namespace std;
int comp_count = 0;

int Partition(int array[], int left, int right) 
{
    int pivot = array[right];
    int j = left;
    for (int i = left; i < right; ++i) 
    {   
        ++comp_count;
        if (array[i] <= pivot) 
        {
            swap(array[i], array[j]);
            ++j;
        }
    }
    swap(array[j], array[right]);
    return j;
}

void QuickSort(int array[], int left, int right) // index right is gonna be a pivot index
{
    if (left+1 < right) 
    {
        int p = Partition(array, left, right);
        QuickSort(array, left, p-1);
        QuickSort(array, p+1, right);
    }
}

int main() 
{
    // int array[] = {3,4,1,5,6,8,2,10,9,7};
    // int array[] = {23,42,23,53,5,7,8,34,1,8,5,95,4,75,34};
    int array[] = {1,2,3,4,5,6,7,8,9,10}; // worst case
    int num = sizeof array / sizeof(array[0]);
    QuickSort(array, 0, num-1);
    for (int i = 0; i < num; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << "comp count : " << comp_count << endl;
}