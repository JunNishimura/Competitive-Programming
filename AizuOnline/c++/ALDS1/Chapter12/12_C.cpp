#include <iostream> 
#include <queue>
#include <algorithm>
#define MAX 1000
#define INF (1<<21)
#define WHITE 0
#define GRAY  1
#define BLACK 2
using namespace std;

int n;
vector<pair<int, int>> adj_list[MAX];

void Dijkstra() 
{
    priority_queue<pair<int,int>> PQ;
    int next, min_cost;
    int color[n], dist[n];

    for (int i = 0; i < n; ++i) 
    {
        color[i] = WHITE;
        dist[i] = INF;
    }

    dist[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;

    while(! PQ.empty())
    {
        pair<int, int> next = PQ.top(); PQ.pop();
        int u = next.second;

        color[u] = BLACK;

        if (dist[u] < next.first * (-1)) continue;

        for (int i = 0; i < adj_list[u].size(); ++i) 
        {
            int v = adj_list[u][i].first;
            if (color[v] == BLACK) continue;
            if (dist[v] > dist[u] + adj_list[u][i].second)
            {
                color[v] = GRAY;
                dist[v] = dist[u] + adj_list[u][i].second;
                PQ.push(make_pair(dist[v]*(-1), v));
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) 
    {
        cout << i << ' ' << (dist[i] != INF ? dist[i] : -1) << endl; 
    }
}

int main() 
{
    int id, deg, v, w;

    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j) 
        {
            cin >> v >> w;
            adj_list[id].push_back(make_pair(v, w));
        }
    }

    Dijkstra();

    return 0;
}