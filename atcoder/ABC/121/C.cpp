#include <bits/stdc++.h> 
using namespace std; 

int main() 
{
    int N, M;
    cin >> N >> M;
    unsigned long long money = 0;
    vector<pair<unsigned long long, int>> v(N);

    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) 
    {
        if ( M <= 0 ) break;

        int m = min(M, v[i].second);
        M -= m;
        money += v[i].first * m;
    }   
    cout << money << endl;
}