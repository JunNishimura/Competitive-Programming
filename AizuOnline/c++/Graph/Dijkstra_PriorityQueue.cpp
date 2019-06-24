#include <iostream> 
#include <algorithm> 
#include <queue> 
using namespace std; 

static const int INF = (1<<21);
static const int WHITE = 0;
static const int BLACK = 1;
static const int MAX = 10000;

int n;
vector<pair<int, int>> adjM[MAX];

void dijkstra() 
{
    priority_queue<pair<int, int>> PQ;
    int color[MAX], dist[MAX];

    for (int i = 0; i < n; ++i) 
    {
        color[i] = WHITE;
        dist[i]  = INF;
    }

    dist[0] = 0;
    PQ.push(make_pair(0, 0));

    while (! PQ.empty())
    {
        pair<int, int> f = PQ.top(); PQ.pop();
        int cur_node = f.second;
        color[cur_node] = BLACK;

        if (dist[cur_node] < f.first * (-1)) continue;

        for (int i = 0; i < adjM[cur_node].size(); ++i) 
        {
            int v = adjM[cur_node][i].first;
            if (color[v] == BLACK) continue;
            if (dist[v] > adjM[cur_node][i].second + dist[cur_node])
            {
                dist[v] = adjM[cur_node][i].second + dist[cur_node];
                PQ.push(make_pair(dist[v] * (-1), v));
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
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j) 
        {
            cin >> d_id >> weight;
            adjM[id].push_back(make_pair(d_id, weight));
        }
    }

    dijkstra();
}