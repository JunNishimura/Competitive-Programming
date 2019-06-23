#include <iostream> 
#include <vector>
#include <stack> 
#define MAX 100000
#define NIL -1
using namespace std;

int m, n;
int color[MAX];
vector<int> G[MAX];

void DepthFirstSearch(int s, int c) 
{
    stack<int> S;
    S.push(s);
    color[s] = c;
    while (!S.empty())
    {
        int t = S.top(); S.pop();
        for (int i = 0; i < G[t].size(); ++i)
        {
            int v = G[t][i];
            if (color[v] == NIL) 
            {
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor() 
{
    for (int i = 0; i < MAX; ++i) color[i] = NIL;

    int col = 0;
    for (int i = 0; i < m; ++i)
    {
        if (color[i] == NIL)
        {
            DepthFirstSearch(i, col++);
        }
    }
}

int main() 
{
    int k, l, q;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) 
    {
        cin >> k >> l;
        G[k].push_back(l);
        G[l].push_back(k);
    }

    assignColor();

    cin >> q;
    for (int i = 0; i < q; ++i) 
    {
        cin >> k >> l;
        if (color[k] == color[l]) printf("yes\n");
        else printf("no\n");
    }
}