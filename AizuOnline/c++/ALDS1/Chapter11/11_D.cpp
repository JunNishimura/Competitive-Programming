#include <iostream> 
#include <vector> 
#include <stack>
#define MAX 100000
using namespace std;

vector<int> Graph[MAX+1];
int color[MAX+1], col(0);

void AssignColor(int node, int col) 
{
    stack<int> S;
    color[node] = col;
    S.push(node);

    while(! S.empty())
    {
        int current_node = S.top(); S.pop();
        for (int i = 0; i < Graph[current_node].size(); ++i) 
        {
            int next = Graph[current_node][i];
            if (color[next] == -1) 
            {
                color[next] = col;
                S.push(next);
            } 
        }
    }
}

int main() 
{
    int node_num, edge_num, node1, node2;
    int q;
    cin >> node_num >> edge_num;
    for (int i = 0; i < node_num+1; ++i) 
    {
        color[i] = -1;
    }

    for (int i = 0; i < edge_num; ++i) 
    {
        cin >> node1 >> node2;
        Graph[node1].push_back(node2);
        Graph[node2].push_back(node1);
    }

    for (int i = 0; i < node_num; ++i)
    {
        if (color[i] < 0) 
        {
            AssignColor(i, col++);
        }
    }
    
    cin >>  q;
    for (int i = 0; i < q; ++i) 
    {
        cin >> node1 >> node2;
        if (color[node1] == color[node2]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}