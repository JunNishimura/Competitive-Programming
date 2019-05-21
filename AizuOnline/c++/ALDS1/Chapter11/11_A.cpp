#include <iostream> 
using namespace std;

static const int M_SIZE = 100;

int main() 
{
    int adj_M[M_SIZE][M_SIZE];
    int n, v_id, v_degree, adj_v;
    cin >> n;

    // init
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            adj_M[i][j] = 0;
        }
    }


    for (int i = 0; i < n; ++i) 
    {
        cin >> v_id >> v_degree;
        v_id--;
        for (int j = 0; j < v_degree; ++j) 
        {
            cin >> adj_v;
            adj_v--;
            adj_M[v_id][adj_v] = 1;
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (j) cout << " ";
            cout << adj_M[i][j];
        }
        cout << endl;
    }
}