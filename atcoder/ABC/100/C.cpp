#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int N; cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++) 
    {
        int t = 0;
        cin >> t;
        
        int j = 0;
        while (t % 2 == 0)
        {
            t /= 2;
            j++;
        }
        ans += j;
    }
    cout << ans << endl;
}