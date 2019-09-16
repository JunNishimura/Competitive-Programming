#include <iostream> 
using namespace std;

int A[100];
int n;

void SWAP(int i, int j) 
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void Show_array()
{
    for (int i = 0; i < n; ++i) 
    {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void Selection_Sort() 
{
    int min_id;
    for (int i = 0; i < n-1; ++i)
    {
        min_id = i;
        for (int j = i+1; j < n; ++j) 
        {
            if (A[j] < A[min_id]) min_id = j;
        }
        if (min_id != i) SWAP(min_id, i);
    }
    Show_array();
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    Selection_Sort();
}