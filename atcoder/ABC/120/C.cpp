#include <bits/stdc++.h>
using namespace std; 

int main() 
{
    string s;
    int b_num=0, r_num=0;
    cin >> s;

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '0') r_num++;
        else b_num++;
    }
    cout << min(b_num, r_num) * 2 << endl;
}