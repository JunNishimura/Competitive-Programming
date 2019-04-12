#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};
Node* head;
Node* GetNewNode(int _data)
{
    Node* newNode = new Node();
    newNode->data = _data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtHead(int _data) 
{
    Node* newNode = GetNewNode(_data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int _data) 
{
    Node* newNode = GetNewNode(_data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* lastNode = head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void Print() 
{
    Node* temp = head;
    printf("Forward: ");
    while (temp != nullptr)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint() 
{
    Node *temp = head;
    if (temp == nullptr) return;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != nullptr)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = nullptr;
    int n, x;
    printf("How many numbers do you wanna put into a list?\n");
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("What number do you wanna insert into a list?\n");
        scanf(" %d", &x);
        // InsertAtHead(x);
        InsertAtTail(x);
        Print();
        ReversePrint();
    }
    return 0;
}