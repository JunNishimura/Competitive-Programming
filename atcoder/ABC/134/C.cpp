#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> s = a;

    sort(s.rbegin(), s.rend());
    for (int i = 0; i < N; i++) 
    {
        int ans = s[0];
        if (s[0] == a[i]) ans = s[1];
        cout << ans << endl;
    }
}