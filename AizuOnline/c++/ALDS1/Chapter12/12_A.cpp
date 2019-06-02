#include <iostream>
using namespace std;
#define INF 1<<21
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 100

int v_num;
int adjM[MAX+1][MAX+1];

int PrimsAlgorithm() 
{
    int current_vertex;
    int color[v_num+1], min_edge[v_num+1], parent[v_num+1];

    // set init state
    for (int i = 0; i < v_num; ++i)
    {
        color[i] = WHITE;
        min_edge[i] = INF;
        parent[i] = -1;
    }

    min_edge[0] = 0;

    while (true) 
    {
        int min_cost = INF;
        // move to the minimum vertex which can be accessed 
        for (int i = 0; i < v_num; ++i) 
        {
            if (color[i] != BLACK && min_edge[i] < min_cost)
            {
                min_cost = min_edge[i];
                current_vertex = i;
            }
        }

        if (min_cost == INF) break;

        color[current_vertex] = BLACK;

        for (int i = 0; i < v_num; ++i) 
        {
            if (color[i] != BLACK && adjM[current_vertex][i] != -1)
            {
                if (adjM[current_vertex][i] < min_edge[i])
                {
                    min_edge[i] = adjM[current_vertex][i];
                    parent[i] = current_vertex;
                    color[i] = GRAY;
                }
            } 
        }
    }

    int sum = 0;
    for (int i = 0; i < v_num; ++i) 
    {
        if (parent[i] != -1) sum += adjM[i][parent[i]];
    }
    return sum;
}

int main() 
{
    int v;
    cin >> v_num;
    for (int i = 0; i < v_num; ++i) 
    {
        for (int j = 0; j < v_num; ++j)
        {
            cin >> v;
            adjM[i][j] = v != -1 ? v : INF;
        }
    }
    
    cout << PrimsAlgorithm() << endl;
}