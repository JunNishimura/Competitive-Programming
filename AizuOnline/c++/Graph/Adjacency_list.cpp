#include <iostream> 
#include <vector> 
using namespace std;

int n;

int main() 
{
    int id, deg, k;
    cin >> n;
    vector<int> adj_list[n];

    for (int i = 0; i < n; ++i) 
    {
        cin >> id >> deg;
        for (int j = 0; j < deg; ++j)
        {   
            cin >> k;
            adj_list[id-1].push_back(k-1);
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << "vertex" << i+1 << ": ";
        for (vector<int>::iterator it = adj_list[i].begin(); it != adj_list[i].end(); ++it) 
        {
            cout << *it << ' ';
        }
        cout << endl;
    }
}