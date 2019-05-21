#include <iostream> 
#include <stack>
using namespace std;

static const int M_NUM = 100;
static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;

int adj_M[M_NUM][M_NUM];
int v_num, Time(0);
int visit_state[M_NUM], D_time[M_NUM], C_time[M_NUM];

int Get_Next_Vertex(int cur_v) 
{
    for (int i = 0; i < v_num; ++i) 
    {
        if (adj_M[cur_v][i] == 1 && visit_state[i] == WHITE)
        {
            return i;
        }
    }
    return -1;
}

void DepthFirstSearch(int init) 
{
    stack<int> S;
    S.push(init);
    visit_state[init] = GRAY;
    D_time[init] = ++Time;
    
    while(! S.empty())
    {
        int cur_v = S.top();
        int next = Get_Next_Vertex(cur_v);
        if (next != -1) 
        {
            S.push(next);
            visit_state[next] = GRAY;
            D_time[next] = ++Time;
        }
        else 
        {
            S.pop();
            visit_state[cur_v] = BLACK;
            C_time[cur_v] = ++Time;
        }
    }
}

void DepthFirstSearch_Recursion(int vertex) 
{
    visit_state[vertex] = GRAY;
    D_time[vertex] = ++Time;

    // search next
    for (int i = 0; i < v_num; ++i)
    {
        if (adj_M[vertex][i] && visit_state[i] == WHITE) DepthFirstSearch_Recursion(i);
    }
    visit_state[vertex] = BLACK;
    C_time[vertex] = ++Time;
}

int main() 
{
    int v_id, v_degree, adj_v;
    cin >> v_num;

    for (int i = 0; i < v_num; ++i) 
    {
        for (int j = 0; j < v_num; ++j) 
        {
            adj_M[i][j] = 0;
        }
    }

    for (int i = 0; i < v_num; ++i) 
    {
        cin >> v_id >> v_degree;
        v_id--;
        for (int j = 0; j < v_degree; ++j) 
        {
            cin >> adj_v;
            adj_v--;
            adj_M[v_id][adj_v] = 1;
        }
    }

    for (int i = 0; i < v_num; ++i) visit_state[i] = WHITE;

    for (int i = 0; i < v_num; ++i) if (visit_state[i] == WHITE) DepthFirstSearch_Recursion(i);

    for (int i = 0; i < v_num; ++i) 
    {
        cout << i + 1 << " " << D_time[i] << " " << C_time[i] << endl;
    }
}