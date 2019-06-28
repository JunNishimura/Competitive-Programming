#include <iostream> 
using namespace std;

void peakFinding(int array[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        int flag = 0;
        if (i == 0)
        {
            if (array[i] > array[i+1]) flag = 1;
        }
        else if (i == size-1) 
        {
            if (array[i] > array[i-1]) flag = 1;
        }
        else 
        {
            if (array[i] > array[i-1] && array[i] > array[i+1]) flag = 1;
        }

        if (flag) cout << array[i] << " is a peak" << endl;
    }
}

int peakFinding2(int array[], int left, int right)
{
    int middle = (left + right) / 2;
    if ((middle == 0 || array[middle] > array[middle-1]) &&
         (middle == right-1 || array[middle] > array[middle+1]))
    {
        return array[middle];
    }
    else if (array[middle] < array[middle-1]) return peakFinding2(array, left, middle-1);
    else return peakFinding2(array, middle+1, right);
}

int main() {
    int array[9] = {1,2,3,4,5,4,3,2,1};
    int size = sizeof(array) / sizeof(*array);
    cout << peakFinding2(array, 0, size-1) << endl;
}