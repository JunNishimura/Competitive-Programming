#include <iostream>
#define MAX_SIZE 101
using namespace std;

int Queue[MAX_SIZE];
int head=-1, tail=-1;

bool isEmpty()
{
    if (head == -1 && tail == -1) return true;
    return false;
}

bool isFull()
{
    if (tail == MAX_SIZE-1) return true;
    return false;
}

void ENQUEUE(int x)
{
    if ((tail + 1)%MAX_SIZE == head) return;
    else if (isEmpty())
    {
        head = 0;
        tail = 0;
    }
    else 
    {
        tail = (tail + 1) % MAX_SIZE;
    }
    Queue[tail] = x;
}

int DEQUEUE()
{
    if (!isEmpty()) return 0;
    else if (head == tail) 
    {
        head = -1;
        tail = -1;
        return 0;
    }
    else 
    {
        head = (head + 1) % MAX_SIZE;
        return Queue[head];
    }
}

int main() 
{
    
    return 0;
}