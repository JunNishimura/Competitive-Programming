#include <iostream> 
#include <vector> 
#include <stack>
#include <queue>
#define MAX 100
#define NIL -1
using namespace std;

vector <int> adjList[MAX];
int color[MAX];
int n, m, q;

void bfs(int s, int col) 
{
    queue<int> Q;
    
    Q.push(s);
    color[s] = col;

    while (!Q.empty()) 
    {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < adjList[v].size(); ++i) 
        {
            int u = adjList[v][i];
            if (color[u] == NIL) 
            {
                Q.push(u);
                color[u] = col;
            }
        }
    }
}

void dfs(int s, int col) 
{
    stack<int> S;

    S.push(s);
    color[s] = col;

    while(!S.empty())
    {
        int v = S.top(); S.pop();
        for (int i = 0; i < adjList[v].size(); ++i) 
        {
            int u = adjList[v][i];
            if (color[u] == NIL) 
            {
                color[u] = col;
                S.push(u);
            }
        }
    }
}

void assignColor() 
{
    int col = 0;

    for (int i = 0; i < n; ++i) 
    {
        color[i] = NIL;
    }

    for (int i = 0; i < n; ++i) 
    {
        if (color[i] == NIL) 
        {
            dfs(i, col++);
        }
    }
}

int main() 
{   
    int s, t;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
    {
        cin >> s >> t;
        adjList[s].push_back(t);
        adjList[t].push_back(s);
    }

    assignColor();

    cin >> q;
    for (int i = 0; i < q; ++i) 
    {
        cin >> s >> t;
        if (color[s] == color[t])
        {
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
}