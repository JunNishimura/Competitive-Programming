#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
};

Node *top;

void PUSH(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int POP()
{
    if (top == nullptr) return 0;
    Node *temp = top;
    int data = temp->data;
    top = temp->next;
    delete temp;
    return data;
}

int main() 
{
    top = nullptr;
    int a1, a2;
    char ch[3];
    while (cin >> ch) 
    {
        if (ch[0] == '+') {
            a1 = POP();
            a2 = POP();
            PUSH(a1+a2);
        } else if (ch[0] == '-') {
            a1 = POP();
            a2 = POP();
            PUSH(a2-a1);
        } else if (ch[0] == '*') {
            a1 = POP();
            a2 = POP();
            PUSH(a1*a2);
        } else {
            PUSH(atoi(ch));
        }
    }
    printf("%d\n", POP());
    return 0;
}