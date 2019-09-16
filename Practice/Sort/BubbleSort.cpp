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

void BubbleSort() 
{
    int cnt = 0;
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = n-1; j > i; --j)
        {
            if (A[j] < A[j-1])
            {
                SWAP(j, j-1);
                cnt ++;
            }
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

    BubbleSort();

    // ShowArray();
}