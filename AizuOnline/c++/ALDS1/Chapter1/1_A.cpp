#include <iostream>
using namespace std; 

int A[101];

void Show_Array(int n)
{
    for (int i = 0; i < n; ++i) 
    {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void Inserttion_Sort(int n) 
{
    Show_Array(n);
    for (int i = 1; i < n; ++i) 
    {
        int target = A[i];
        int j = i-1;
        while (j >= 0 && target < A[j]) 
        {
            A[j+1] = A[j];
            --j;
        }
        A[++j] = target;

        // print out 
        Show_Array(n);
    }
}

int main() 
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    Inserttion_Sort(n);
    
}