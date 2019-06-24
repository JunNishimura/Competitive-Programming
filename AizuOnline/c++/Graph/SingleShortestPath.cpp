#include <iostream> 
using namespace std;

static const int INF = (1<<21);
static const int WHITE = 0;
static const int BLACK = 1;
static const int MAX = 100;

int n;
int color[MAX], dist[MAX];
int M[MAX][MAX];

void dijkstra() 
{
    // initialize
    for (int i = 0; i < n; ++i) 
    {
        color[i] = WHITE;
        dist[i] = INF;
    }
    // set 0 as the start node
    dist[0] = 0;

    while (1) 
    {
        int curN = -1;
        int min_cost = INF;
        for (int i = 0; i < n; ++i)
        {
            if (color[i] != BLACK && dist[i] < min_cost)
            {
                min_cost = dist[i];
                curN = i;
            }
        }

        if (curN == -1) break;

        color[curN] = BLACK;

        for (int i = 0; i < n; ++i) 
        {
            if (dist[curN] + M[curN][i] < dist[i] && color[i] != BLACK && M[curN][i] != INF)
            {
                dist[i] = dist[curN] + M[curN][i];
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << i << " " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() 
{
    int id, deg, d_id, weight;
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            M[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j) 
        {
            cin >> d_id >> weight;
            M[id][d_id] = weight;
        }
    }

    dijkstra();
}