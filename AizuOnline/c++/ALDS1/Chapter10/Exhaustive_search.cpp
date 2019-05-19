#include <iostream> 
using namespace std;

int A[2000], n, m;
int DP[100][100];

bool ExhaustiveSearch(int id, int target) 
{
    if (DP[id][target] != -1) return DP[id][target];

    if (target == 0) DP[id][target] = true;
    else if (id >= n) DP[id][target] = false;
    

    return ExhaustiveSearch(id+1, target-A[id]) || ExhaustiveSearch(id+1, target);
}

int main () 
{
    int tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; ++i) 
    {   
        cin >> tmp;
        if (ExhaustiveSearch(i, tmp))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        
    }
}