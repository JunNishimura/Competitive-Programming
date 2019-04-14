#include <iostream>
using namespace std;

int main() {
    int n, q, c = 0, T;
    int S[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T);
        for (int j = 0; j < n; j++) {
            if (T == S[j]) {
                c++;
                break;
            }
        }
    }
    printf("%d\n", c);
    return 0;
}