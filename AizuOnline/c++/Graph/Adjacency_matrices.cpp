#include <iostream> 
#define N 101
using namespace std;

int n;
int adj_m[N][N];

int main() 
{
    int id, deg, k;
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            adj_m[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j) 
        {
            cin >> k;
            adj_m[id-1][k-1] = 1;
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << adj_m[i][j] << ' ';
        }
        cout << endl;
    }
}  