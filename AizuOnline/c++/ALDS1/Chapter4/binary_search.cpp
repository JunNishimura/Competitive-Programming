#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main () {
    vector<int> V;
    int n, q, c = 0, T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t = 0; scanf("%d", &t);
        V.push_back(t);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T);
        if (binary_search(V.begin(), V.end(), T)) c++;
    }
    printf("%d\n", c);
    return 0;
}