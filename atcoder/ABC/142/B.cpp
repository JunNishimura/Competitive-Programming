#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    int ans = 0;
    for (int i = 0; i < N; i++) 
    {
        if (v[i] >= K) ans++;
    }
    cout << ans << endl;
}