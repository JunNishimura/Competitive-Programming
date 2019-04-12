#include <iostream>
using namespace std;

struct Node
{
    unsigned int data;
    Node *prev = nullptr;
    Node *next = nullptr;
};
Node *head, *tail;

void Insert(int _data)
{ 
    Node *newNode = new Node();
    newNode->data = _data;
    newNode->next = head;
    if (head == nullptr) tail = newNode;
    if (head != nullptr) head->prev = newNode;
    head = newNode;

}

void DeleteFirst()
{
    if (head == nullptr) return;
    if (head->next == nullptr) 
    {
        delete head;
        head = nullptr;  
        tail = nullptr;  
    }
    else
    {
        Node *nextHead = head->next;
        nextHead->prev = nullptr;
        delete head;
        head = nextHead;
    }
}

void DeleteLast()
{
    if (tail == nullptr) return;
    if (tail->prev == nullptr)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        Node *prevTail = tail->prev;
        prevTail->next = nullptr;
        delete tail;
        tail = prevTail;
    }
    
    
}

void Delete(int _data)
{
    if (head == nullptr) return;
    Node *temp = head;
    while (temp->data != _data)
    {
        temp = temp->next;
        if (temp == nullptr) return;
    }
    if (temp->prev == nullptr) DeleteFirst();
    else if (temp->next == nullptr) DeleteLast();
    else 
    {
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        delete temp;
    }
}

void Print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp != head) printf(" ");
        printf ("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int n = 0;
int main()
{
    head = nullptr, tail = nullptr;
    char ch[10]; int v;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", ch, &v);
        if (ch[0] == 'i') Insert(v);
        else if (ch[6] == 'F') DeleteFirst();
        else if (ch[6] == 'L') DeleteLast();
        else Delete(v);
    }
    Print();
    return 0;
}