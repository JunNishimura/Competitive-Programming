#include <iostream>
#define MAX_SIZE 101
using namespace std;

class Stack
{
private:
    int A[MAX_SIZE];
    int top; // 入力済みの配列先頭インデックスを指す
public:
    Stack();
    void PUSH(int x);
    int POP();
    bool isEmpty();
};

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    if (top == -1) return true;
    else return false;
}

void Stack::PUSH(int x)
{
    A[++top] = x;
}

int Stack::POP()
{
    if (!isEmpty())
    {
        return A[top--];
    }
    return 0;
}

int main() 
{
    int a, b;
    Stack s;
    char ch[3];
    while (cin >> ch)
    {
        if (ch[0] == '+')
        {
            a = s.POP(); b = s.POP();
            s.PUSH(a+b);
        }
        else if (ch[0] == '-')
        {
            a = s.POP(); b = s.POP();
            s.PUSH(b-a);
        }
        else if (ch[0] == '*')
        {
            a = s.POP(); b = s.POP();
            s.PUSH(a*b);
        }
        else 
        {
            s.PUSH(atoi(ch));
        }
    }
    printf("%d\n", s.POP());
    return 0;
}