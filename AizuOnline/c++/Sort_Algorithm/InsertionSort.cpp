#include <iostream> 
using namespace std;

int swap_count = 0;

void InsertionSort(int array[], int num) 
{
    int j;
    for (int i = 1; i < num; ++i) 
    {
        int tmp = array[i];
        for (j = i-1; j >= 0; j--)
        {
            if (array[j] > tmp) 
            {
                array[j+1] = array[j];
                ++swap_count;
            }
            else break;
        }
        array[j+1] = tmp;
    }
}

int main() 
{
    int array[] = {4,1,3,5,2};
    // int array[] = {5,4,3,2,1}; // worst case
    // int array[] = {1,2,3,4,5}; // best case 
    InsertionSort(array, 5);
    for (int i = 0; i < 5; ++i) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "swap count : " << swap_count << endl;
}