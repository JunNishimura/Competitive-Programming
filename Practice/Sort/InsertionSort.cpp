#include <iostream> 
using namespace std; 

int A[100]; 
int n;

void ShowArray() 
{
    for (int i = 0; i < n; i++) 
    {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void InsertionSort() 
{
    for (int i = 1; i < n; i++) 
    {
        int t = A[i];
        int j = i;
        while (j > 0 && t < A[j-1])
        {
            A[j] = A[j-1];
            --j;
        }
        A[j] = t;
        ShowArray();
    }
}

int main() 
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }

    InsertionSort();

    // ShowArray();
}