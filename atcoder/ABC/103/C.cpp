#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int t; cin >> t;
        ans += t-1;
    }
    cout << ans << endl;
}