#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int ans=0;
    int N; cin >> N;
    string S; cin >> S;
    
    for (int i = 1; i < S.length()-1; i++) 
    {
        int cur_ans = 0;
        map<char, int> m1, m2;
        for (int j = 0; j < i; j++) 
        {
            m1[S[j]]++;
        }
        for (int j = i; j < S.length(); j++) 
        {
            m2[S[j]]++;
        }
        
        for (auto i = m1.begin(); i != m1.end(); i++) 
        {
            if (m2.find(i->first) != m2.end()) cur_ans++;
        }
        ans = max(ans, cur_ans);
    }

    cout << ans << endl;
}