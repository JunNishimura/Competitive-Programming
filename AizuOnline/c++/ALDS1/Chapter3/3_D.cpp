#include <iostream>
#include <stack>
#include <utility>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

stack<int> S1;
stack<pair<int, int>> S2;
int k = 0;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '\\') {
            S1.push(i);
        } else if (s[i] == '/' && !S1.empty()) {
            int j = S1.top(); S1.pop();
            pair<int, int> newPair = make_pair(j, i-j);
            while (!S2.empty() && S2.top().first > j) 
            {
                newPair.second += S2.top().second;
                S2.pop();
            }
            S2.push(newPair);
        }
    }

    vector<int> v;
    while(!S2.empty()) {
        v.push_back(S2.top().second);
        S2.pop();
    }
    reverse(v.begin(), v.end());
    printf("%d\n", accumulate(v.begin(), v.end(), 0));
    printf("%d", v.size());
    for (int i = 0; i < v.size(); i++) printf(" %d", v[i]);
    printf("\n");
}