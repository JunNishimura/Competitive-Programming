#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() 
{
    cin >> N;
    map<string, int> m;
    for (int i = 0; i < N; i++) 
    {
        string t; cin >> t;
        m[t]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string t; cin >> t;
        m[t]--;
    }

    int ans = 0;
    for (auto i = m.begin(); i != m.end(); i++) 
    {
        ans = max(ans, i->second);
    }
    cout << ans << endl;
}