#include <iostream>
using namespace std;

int S[100000];

bool BinarySearch(int n, int key) 
{
    int head = 0, tail = n;
    while (head < tail) 
    {
        int target = (head + tail) / 2;
        if (key == S[target]) return true;
        else if (key < S[target]) tail = target;
        else if (key > S[target]) head = target+1;
    }
    return false;
}

int main () {
    int n, q, c = 0, T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T);
        if (BinarySearch(n, T)) c++;
    }
    printf("%d\n", c);
    return 0;
}