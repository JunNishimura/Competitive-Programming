#include <iostream> 
using namespace std;

int swap_count = 0;

void BubbleSort(int array[], int num)
{ 
    for (int i = 0; i < num; ++i)
    {
        for (int j=num-1; j > i; --j) 
        {
            if (array[j-1] > array[j]) 
            {
                swap(array[j-1], array[j]);
                ++swap_count;
            }
        }
    }
}

int main() 
{
    // int array[] = {3,4,1,5,6,8,2,10,9,7};
    int array[] = {10,9,8,7,6,5,4,3,2,1}; // worst case 

    BubbleSort(array, 10);
    for (int i = 0; i < 10; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << "swap count : " << swap_count << endl;
}