#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
};

Node *head, *tail;

void Enqueue(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    if (tail != nullptr) tail->next = newNode;
    tail = newNode;
    if (head == nullptr) head = newNode;
}

int Dequeue()
{
    if (head == nullptr) {
        printf("nothing to dequeue\n");
        return -1;
    }
    Node *temp = head;
    int data = temp->data;
    head = temp->next;
    delete temp;
    return data;
}

void Print()
{
    if (head == nullptr) {
        printf("list is empty.\n");
        return;
    }
    Node *temp = head;
    printf("list:");
    while (temp != nullptr) 
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = nullptr;
    tail = nullptr;
    Enqueue(10); Print();
    Enqueue(5); Print();
    int a = Dequeue(); printf("dequeue val: %d ", a); Print();
    a = Dequeue(); printf("dequeue val: %d ", a); Print();
    a = Dequeue(); printf("dequeue val: %d ", a); Print();
    return 0;
}