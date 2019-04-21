#include <iostream>

int F[50];
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        if (i <= 1) F[i] = 1;
        else {
            F[i] = F[i-1] + F[i-2];
        }
    }
    printf("%d\n", F[n]);
}