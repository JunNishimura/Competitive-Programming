#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> a(N);
    int sum, mean, ans=0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0) mean = sum / N;
    else mean = (sum+1) / N;
    for (int i = 0; i < N; i++) 
    {
        ans += pow(a[i]-mean, 2);
    }
    cout << ans << endl;
}