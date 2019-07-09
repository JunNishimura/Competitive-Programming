#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int val;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node* create_node(int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insert_at_head(int val) 
{
    struct Node *newNode = create_node(val);

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;

    head = newNode;
}

void insert_at_tail(int val) 
{
    struct Node *newNode = create_node(val);

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    struct Node *tmp_node = head;

    while(tmp_node->next != NULL) 
    {
        tmp_node = tmp_node->next;
    }

    tmp_node->next = newNode;
    newNode->prev = tmp_node;
}

void print_list() 
{
    struct Node *tmp_node = head;

    while (tmp_node != NULL) 
    {
        printf("%d", tmp_node->val);
        if (tmp_node->next != NULL) printf("->");
        tmp_node = tmp_node->next;
    }
    printf("\n");
}

struct Node* search_node(int val) 
{
    if (head == NULL) return NULL;

    struct Node *tmp_node = head;
    while (tmp_node != NULL) 
    {
        if (tmp_node->val == val) return tmp_node;

        tmp_node = tmp_node->next;
    }

    return NULL;
}

void remove_node(int val) 
{
    struct Node *tmp_node = search_node(val);

    if ( tmp_node != NULL ) 
    {
        if (tmp_node == head) 
        {
            tmp_node->next->prev = NULL;
            head = tmp_node->next;
        }
        else 
        {
            tmp_node->prev->next = tmp_node->next;
            tmp_node->next->prev = tmp_node->prev;
        }
        printf("remove %d\n", val);
        free(tmp_node);
    } 
    else 
    {
        printf("there is no node whose value is %d\n", val);
    }
}

// void insert(int key) 
// {
//     struct Node *newNode = create_node(key);

//     struct Node *tmp_node = head;
//     while (tmp_node != NULL) 
//     {
//         if (tmp_node->val > newNode->val) 
//         {
//             tmp_node = tmp_node->next;
//         } 
//         else break;
//     }
//     newNode->next = tmp_node->next;
//     newNode->prev = tmp_node;
//     tmp_node
    
// }

int main() 
{
    head = NULL;
    insert_at_head(10);
    insert_at_head(15);
    insert_at_head(4);
    insert_at_tail(9);
    insert_at_tail(8);

    print_list();

    remove_node(3);
    remove_node(9);
    remove_node(4);

    print_list();
}