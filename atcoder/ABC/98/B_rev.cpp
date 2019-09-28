#include <bits/stdc++.h>
using namespace std;

int func(string s1, string s2)
{
    int ans = 0;
    for (char c = 'a'; c <='z'; c++) 
    {
        bool found_s1 = false, found_s2 = false;
        for (int i = 0; i < s1.length(); i++) 
        {
            if (s1[i] == c) found_s1 = true;
        }
        for (int i = 0; i < s2.length(); i++) 
        {
            if (s2[i] == c) found_s2 = true;
        }
        if (found_s1 && found_s2) ans++; 
    }
    return ans;
}

int main() 
{
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i = 0; i <= N; i++) 
    {
        int tmp = func(S.substr(0, i), S.substr(i));
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}