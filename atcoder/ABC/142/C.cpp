#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) 
    {
        int t;
        cin >> t;
        v[i] = make_pair(t, i+1);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) 
    {
        if (i) cout << " ";
        cout << v[i].second;
    }
    cout << endl;
}