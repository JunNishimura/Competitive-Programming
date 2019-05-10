#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next = NULL;
};

bool Checker(Node **pointerToHead, int index, const char *order)
{
    Node *temp = *pointerToHead;
    int sizeOfList = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        sizeOfList++;
    }
    if (order[0] == 'I')
    {
        if (index > sizeOfList+1) 
        {
            printf("Sorry, you cannot insert that position. The position you can insert is");
            for (int i = 0; i < sizeOfList+1; i++)
            {
                printf(" %d", i+1);
                if (i == sizeOfList) printf(".\n");
            }
            return false;
        }
    }
    else if (order[0] == 'D')
    {
        if (index > sizeOfList)
        {
            printf("Sorry, you cannot delete that position. The position you can delete is");
            for (int i = 0; i < sizeOfList; i++)
            {
                printf(" %d", i+1);
                if (i == sizeOfList-1) printf(".\n");
            }
            return false;
        }
    }
    return true;
}

// Node *head; // global variable

Node* Insert(Node* _head, int _data) 
{
    Node *temp = new Node;
    temp->data = _data;
    temp->next = _head;
    _head = temp;
    return _head;
}

void InsertNthPos(Node **pointerToHead, int _data, int index)
{
    Node *newNode = new Node();
    newNode->data = _data;
    // error check
    char order[] = "Insert";
    if (!Checker(&*pointerToHead, index, order))
    {
        return;
    }

    if (index == 1 || *pointerToHead == NULL)
    {
        newNode->next = *pointerToHead;
        *pointerToHead = newNode;
    }
    else 
    {
        int i = 1;
        Node *prev = *pointerToHead;
        while (i < index-1)
        {
            prev = prev->next;
            i++;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void Delete(Node **pointerToHead, int index)
{
    // error check
    char order[] = "Delete";
    if (!Checker(&*pointerToHead, index, order))
    {
        return;
    }

    Node *prev = *pointerToHead;
    if (index == 1)
    {
        *pointerToHead = prev->next;
        delete prev;
    }
    else 
    {
        int i = 1;
        while (i < index-1)
        {
            prev = prev->next;
            i++;
        }
        Node *del_target = prev->next;
        prev->next = del_target->next;
        delete del_target;
    }
}

void Print(Node *_head)
{
    printf("List is :");
    while (_head != NULL)
    {
        printf(" %d", _head->data);
        _head = _head->next;
    }
    printf("\n");
}

int main() 
{
    Node *head = NULL;
    printf("How many numbers?\n");
    int n, x, index;
    char ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Write down the value of data.\n");
        scanf("%d", &x);
        printf("Where do you put this number?\n");
        scanf("%d", &index);
        InsertNthPos(&head, x, index);
        printf("Do you want to delete some data? (y/n)\n");
        scanf(" %c", &ans);
        if (ans == 'y')
        {
            printf("Which position do you want to delete?\n");
            scanf("%d", &index);
            Delete(&head, index);
        }
        Print(head);
    }
}