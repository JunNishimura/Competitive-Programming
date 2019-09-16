#include <iostream> 
using namespace std;

int A[101];
int n;

void Show_array() 
{
    for (int i = 0; i < n; ++i) 
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

void Bubble_Sort() 
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = n-1; j > i; j--) 
        {
            if (A[j] < A[j-1]) SWAP(j, j-1);
        }
        Show_array();
    }
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    Show_array();
    Bubble_Sort();
}