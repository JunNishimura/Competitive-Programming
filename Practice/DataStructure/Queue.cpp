#include <iostream> 
#define MAX 101
using namespace std;

int Q[MAX];
int n, q;
int head, tail;

bool isFull() 
{
    return tail+1 == MAX;
}

bool isEmpty() 
{
    return head == tail;
}

void enqueue(int value) 
{
    Q[(tail++)%MAX] = value;
}

int dequeue()
{
    return Q[(head++)%MAX];
}

int main() 
{
    cin >> n >> q;
    head = tail = 0;
}