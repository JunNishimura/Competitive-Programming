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

void SWAP(int i, int j) 
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

int main() 
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }



    ShowArray();
}