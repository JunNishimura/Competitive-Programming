#include <iostream> 
#include <vector>
using namespace std; 

int A[100]; 
vector<int> V;
int n;

void ShowArray() 
{
    cout << V.size() << endl;
    for (int i = V.size()-1; i >= 0; i--) 
    {
        if (i != V.size()-1) cout << " ";
        cout << V[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << A[i] << endl;
    }
}

void InsertionSort(int h) 
{
    for (int i = h; i < n; i++) 
    {
        int t = A[i];
        int j = i-h;
        while (j >= 0 && t < A[j])
        {
            A[j+h] = A[j];
            j -= h;
        }
        A[j+h] = t;
    }   
}

void ShellSort() 
{
    for (int i = V.size()-1; i >= 0; --i) 
    {
        InsertionSort(V[i]);
    }
    ShowArray();
}

int main() 
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }

    int i = 0;
    V.push_back(1);
    while (true)
    {
        int h = 3 * V[i] + 1;
        if (h > n) break;
        V.push_back(h);
        ++i;
    }

    ShellSort();
}