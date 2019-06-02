#include <iostream>
#define MAX 100
#define INF (1<<21)
#define WHITE 0
#define GRAY  1
#define BLACK 2
using namespace std;

int n;
int adj_M[MAX][MAX];

int Prims() 
{
    int min_cost, next;
    int parent[n+1], color[n+1], min_edge[n+1];

    for (int i = 0; i < n; ++i) 
    {
        parent[i] = -1;
        min_edge[i] = INF;
        color[i]  = WHITE;
    }

    min_edge[0] = 0;

    while (true)
    {
        min_cost = INF;
        next = -1;
        for (int i = 0; i < n; ++i) 
        {
            if (color[i] != BLACK && min_edge[i] < min_cost)
            {
                min_cost = min_edge[i];
                next = i;
            }
        }

        if (next == -1) break;
        color[next] = BLACK;

        for (int i = 0; i < n; ++i) 
        {
            if (color[i] != BLACK && adj_M[next][i] != INF) 
            {
                if (adj_M[next][i] < min_edge[i]) 
                {
                    min_edge[i] = adj_M[next][i];
                    parent[i]   = next;
                    color[i]    = GRAY;
                } 
            
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (parent[i] != -1) sum += adj_M[i][parent[i]];
    }
    return sum;
}

int main() 
{
    int t;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> t;
            adj_M[i][j] = (t == -1) ? INF : t;
        }
    }

    cout << Prims() << endl;
}