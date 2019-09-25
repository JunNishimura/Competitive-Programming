#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K; 
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h.rbegin(), h.rend());
    int min_dist = 1000000001;
    for (int i = 0; i < N-(K-1); i++) 
    {
        if (h[i] - h[i+(K-1)] < min_dist) min_dist = h[i] - h[i+(K-1)];
    }
    cout << min_dist << endl;
}