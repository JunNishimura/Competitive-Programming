#include <iostream> 
#include <queue>
#include <string> 
#include <algorithm> 
using namespace std;

queue<pair<string, int>> Q;
int n, q, t;
string name;

int main() 
{
    cin >> n >> q;

    for (int i = 0; i < n; i++) 
    {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps, a;

    while (!Q.empty()) 
    {
        u = Q.front(); Q.pop();
        a = min(u.second, q);
        u.second -= a;
        elaps += a;
        if (u.second > 0) Q.push(u);
        else cout << u.first << " " << u.second << endl;
    }
}