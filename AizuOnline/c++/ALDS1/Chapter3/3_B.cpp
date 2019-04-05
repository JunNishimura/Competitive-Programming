#include <iostream>
#define L 100000

struct QUEUE
{
    char name[10];
    int time;
};
int head, tail, n;
QUEUE Q[L];
void enqueue(QUEUE q)
{
    Q[tail] = q;
    tail = (tail+1) % L;
}
QUEUE dequeue()
{
    QUEUE x = Q[head];
    head = (head+1) % L;
    return x;
}
int main() 
{
    head = 0; tail = 0;
    QUEUE tq;
    int q;
    int time=0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) 
    {
        scanf("%s %d", tq.name, &tq.time);
        enqueue(tq);
    }
    while (true)
    {
        if (head == tail) break;
        tq = dequeue();
        tq.time -= q;
        if (tq.time <= 0) //処理完了したら
        {
            time += q+tq.time;
            printf("%s %d\n", tq.name, time);
        } 
        else
        {
            time += q;
            enqueue(tq);
        }
    }
}