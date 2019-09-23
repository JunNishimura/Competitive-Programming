#include <bits/stdc++.h>
using namespace std; 

int N;

int main() 
{   
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    sort(d.begin(), d.end());
    cout << d[d.size()/2] - d[d.size()/2-1] << endl;
}