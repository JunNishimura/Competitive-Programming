#include <iostream> 
#include <queue>
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define MAX   100
using namespace std;

int n;
int adj_matrix[MAX][MAX], color[MAX], DIST[MAX];

void BreadthFirstSearch(int s) 
{
    queue<int> Q;
    Q.push(s);
    DIST[0] = 0;

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        color[cur] = BLACK;
        for (int i = 0; i < n; ++i) 
        {
            if(adj_matrix[cur][i] && color[i] == WHITE)
            {
                Q.push(i);
                DIST[i] = DIST[cur] + 1;
            }
        }
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
        DIST[i] = -1;
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

    // for (int i = 0; i < n; ++i) 
    // {
    //     if(color[i] == WHITE) BreadthFirstSearch(i);
    // }
    BreadthFirstSearch(0);

    for (int i = 0; i < n; ++i) 
    {
        cout << i + 1 << DIST[i] << endl;
    }
}