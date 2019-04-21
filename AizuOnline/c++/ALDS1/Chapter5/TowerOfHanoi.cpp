#include <iostream>
using namespace std;

int cnt = 0;
void Hanoi(int n, char beg, char aux, char end) {
    if (n == 1) { 
        cnt++;
        printf("%c -> %c\n", beg, end);
    }
    else { 
        Hanoi(n-1, beg, end, aux);
        Hanoi(1, beg, aux, end);
        Hanoi(n-1, aux, beg, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');
    printf("minimum count to complete is %d\n", cnt);
}