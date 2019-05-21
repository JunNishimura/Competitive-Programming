#include <iostream> 
#include <queue>
#define NODE_NUM 100
using namespace std;

int v_num, v_degree, v, v_id;
int adj_M[NODE_NUM][NODE_NUM], Distance[NODE_NUM], visit_state[NODE_NUM];
static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;

void BreadthFirstSearch(int node) 
{
    queue<int> Q;
    Q.push(node);
    Distance[node] = 0;
    visit_state[node] = GRAY;

    while(! Q.empty())
    {
        int cur_node = Q.front();
        for (int i = 0; i < v_num; ++i) 
        {
            if (adj_M[cur_node][i] == 1 && visit_state[i] == WHITE) 
            {
                Q.push(i);
                visit_state[i] = GRAY;
                Distance[i] = Distance[cur_node] + 1;
            } 
        } 
        Q.pop();
        visit_state[cur_node] = BLACK;
    }
}

int main() 
{
    cin >> v_num;

    // init
    for (int i = 0; i < v_num; ++i) 
    {
        for (int j = 0; j < v_num; ++j) 
        {
            adj_M[i][j] = 0;
        }
        Distance[i] = -1;
        visit_state[i] = WHITE;
    }

    for (int i = 0; i < v_num; ++i) 
    {
        cin >> v_id >> v_degree;
        v_id--;
        for (int i = 0; i < v_degree; ++i) 
        {
            cin >> v;
            adj_M[v_id][v-1] = 1;
        }
    }

    BreadthFirstSearch(0);

    for (int i = 0; i < v_num; ++i) cout << i+1 << " " << Distance[i] << endl;
}