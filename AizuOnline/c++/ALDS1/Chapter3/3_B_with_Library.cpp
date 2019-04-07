#include <iostream>
#include <queue>
using namespace std;

struct OBJ
{
    int value;
    char name[10];
};
int head, tail, TIME=0;
int main()
{
    int n, q;
    queue<OBJ> Q;
    OBJ t;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", t.name, &t.value);
        Q.push(t);
    }
    tail = n;
    while (head != tail)
    {
        t = Q.front(); Q.pop();
        t.value -= q;
        if (t.value <= 0)
        {
            TIME += q + t.value;
            printf("%s %d\n", t.name, TIME);
        }
        else
        {
            TIME += q;
            Q.push(t);
            tail ++;
        }
        head ++;
    }
}