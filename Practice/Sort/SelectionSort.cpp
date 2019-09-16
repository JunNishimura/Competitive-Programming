#include <iostream> 
using namespace std; 

int A[100]; 
int n;

int h;

void ShowArray() 
{
    for (int i = 0; i < n; i++) 
    {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void SWAP(int i, int j) 
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void SelectionSort()
{
    int cnt = 0;
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++) 
        {
            if (A[j] < A[min]) 
            {
                min = j;
            }
        }
        if (min != i) 
        {
            SWAP(i, min);
            cnt ++;
        }
    }

    ShowArray();
    cout << cnt << endl;
}

int main() 
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }

    SelectionSort();
}