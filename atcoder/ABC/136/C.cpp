#include <iostream> 
#include <vector>
using namespace std; 

int main() 
{
    int N;
    cin >> N; 
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    int prev = -999;
    for (int i = 0; i < N; i++) 
    {
        if (V[i]-1 >= prev) 
        {
            prev = V[i]-1;
        }
        else if (prev == V[i])
        {
            prev = V[i];
        }
        else 
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
