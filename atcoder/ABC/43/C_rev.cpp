#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    long long ans = pow(2, 29);
    for (int i = -100; i <= 100; i++) 
    {
        long long sum = 0;
        for (int j = 0; j < N; j++) 
        {
            sum += pow(a[j] - i, 2);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}