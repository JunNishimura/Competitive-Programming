#include <iostream> 
using namespace std;
int swap_count = 0;

void SelectionSort(int array[], int num)
{
    int s_id;
    for (int i = 0; i < num; ++i) 
    {
        s_id = i;
        for (int j = i+1; j < num; ++j) 
        {
            if (array[s_id] > array[j]) s_id = j;
        }   
        if (s_id != i) 
        {
            swap(array[s_id], array[i]);
            ++swap_count;  
        } 
    }
}

int main() 
{
    // int array[] = {3,4,1,5,6,8,2,10,9,7};
    // int array[] = {10,9,8,7,6,5,4,3,2,1};
    int array[] = {2,3,4,5,6,7,8,9,10,1};  
    SelectionSort(array, 10);
    for (int i = 0; i < 10; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << "swap count : " << swap_count << endl;
}