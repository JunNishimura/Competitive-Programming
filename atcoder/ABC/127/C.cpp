#include <bits/stdc++.h> 
using namespace std;

int N, M;

int main() 
{
    cin >> N >> M;
    int l, r;
    int left = -1000001, right = 100001; 
    bool isSafe = true;
    for (int i = 0; i < M; i++) 
    {
        cin >> l >> r;
        if (l > right || r < left) 
        {
            isSafe = false;
            break;
        }
        left = max(l, left);
        right = min(r, right);
    }
    int ans = right - left + 1;
    if (isSafe) cout << right - left + 1 << endl;
    else cout << 0 << endl;
}