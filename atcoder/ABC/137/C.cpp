#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>
#include <map>
using namespace std;


int main() 
{ 
    int N;
    cin >> N;
    vector<string> V;
    map<string, int> M;
    long long cnt = 0;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        V.push_back(s);
    }

    for (int i = 0; i < N; i++) 
    {
        sort(V[i].begin(), V[i].end());
    }

    for (int i= 0; i < N; i++) 
    {
        if (M.find(V[i]) == M.end()) 
        {
            M.insert(make_pair(V[i], 1));
        }
        else 
        {
            M[V[i]] ++;
        }
    }
 
    for (auto& x: M)
    {
        cnt += x.second * (x.second - 1) / 2;
    }
    
    cout << cnt << endl;
}