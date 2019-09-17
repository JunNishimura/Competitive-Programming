#include <iostream> 
#define MAX 101
using namespace std;

int Stack[MAX];
int top = 0;

bool isFull() 
{
    return top == MAX-1;
}

bool isEmpty() 
{
    return top == 0;
}

void push(int value) 
{
    if (isFull()) return;
    Stack[++top] = value;
}

int pop() 
{
    if (isEmpty()) return 0;
    return Stack[top--];   
}

int main() 
{
    int a, b;
    char c[100];
    while (scanf("%s", c) != EOF) 
    {
        if (c[0] == '+')
        {
            a = pop();
            b = pop();
            push(a+b);
        } 
        else if (c[0] == '-')
        {
            b = pop();
            a = pop();
            push(a-b);
        }
        else if (c[0] == '*')
        {
            a = pop();
            b = pop();
            push(a * b);
        }
        else 
        {
            push(atoi(c));
        }
    }

    printf("%d\n", pop());
}