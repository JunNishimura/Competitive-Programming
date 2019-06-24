#include <iostream> 
#define MAX 100
static const int INFTY (1<<21);
#define WHITE 0
#define GRAY  1
#define BLACK 2
using namespace std;

int n;
int color[MAX], parent[MAX];
int max_weight[MAX];
int M[MAX][MAX];

int PrimAlgorithm() 
{
    for (int i = 0; i < n; ++i) 
    {
        color[i] = WHITE;
        max_weight[i] = INFTY;
        parent[i] = -1;
    }

    int cur = 0;
    max_weight[cur] = 0;

    while (1) 
    {
        color[cur] = BLACK;
        for (int i = 0; i < n; ++i) 
        {
            if (M[cur][i] < max_weight[i] && color[i] != BLACK)
            {
                max_weight[i] = M[cur][i];
                parent[i] = cur;
                color[i] = GRAY;
            }
        }

        int min = INFTY;
        for (int i = 0; i < n; ++i) 
        {
            if (color[i] != BLACK && max_weight[i] < min)
            {
                min = max_weight[i];
                cur = i;
            }
        }

        if (min == INFTY) break;
    }
    
    int total = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (parent[i] != -1) total += M[i][parent[i]];
    }
    return total;
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            int e; cin >> e;
            M[i][j] = e != -1 ? e : INFTY;
        }
    }

    cout << PrimAlgorithm() << endl;
}