#include <iostream> 
#include <stack> 
#define N 100
#define WHITE 0
#define GRAY  1
#define BLACK 2
using namespace std;

int n, TIME(0);
int color[N];
int adj_matrix[N][N];
int DisT[N], ComT[N];


void DFS_visit(int k) 
{
    color[k] = GRAY;
    DisT[k] = ++TIME;
    for (int i = 0; i < n; ++i)
    {
        if (adj_matrix[k][i] && color[i] == WHITE)
        {
            DFS_visit(i);
        }
    }
    color[k] = BLACK;
    ComT[k] = ++TIME;
}

void DepthFirstSearch() 
{
    for (int i = 0; i < n; ++i) 
    {
        if (color[i] == WHITE) DFS_visit(i);
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << i+1 << ' ' << DisT[i] << ' ' << ComT[i] << endl;
    }
}

void SetMatrix() 
{
    int id, deg, k;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            adj_matrix[i][j] = 0; // initialize 
        }
        color[i] = WHITE;
        DisT[i] = 0;
        ComT[i] = 0;
    }

    for (int i = 0; i < n; ++i) 
    {
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j)
        {
            cin >> k;
            adj_matrix[id-1][k-1] = 1;
        }
    }
}

int main() 
{
    SetMatrix();

    DepthFirstSearch();
}