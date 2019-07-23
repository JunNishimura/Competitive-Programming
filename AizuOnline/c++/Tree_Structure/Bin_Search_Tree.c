#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int value;
    struct Node *parent;
    struct Node *l_child;
    struct Node *r_child;
};

struct Node *root;

struct Node* createNode(int value) 
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->parent = NULL;
    newNode->l_child = NULL;
    newNode->r_child = NULL;

    return newNode;
}

void Insert(int value) 
{
    struct Node *newNode = createNode(value);
    struct Node *tmp_node = root, *prev;

    if (root == NULL) 
    {
        root = newNode;
        return;
    }

    while (tmp_node != NULL) 
    {   
        prev = tmp_node;
        if (tmp_node->value > newNode->value) 
        {
            tmp_node = tmp_node->l_child;
        }
        else 
        {   
            tmp_node = tmp_node->r_child;
        }
    }

    if (prev->value > newNode->value) prev->l_child = newNode;
    else prev->r_child = newNode;

    newNode->parent = prev;
    tmp_node = newNode;
}

void preorder(struct Node *node) 
{
    if (node == NULL) return;

    printf("%d ", node->value);
    preorder(node->l_child);
    preorder(node->r_child);
}

void inorder(struct Node *node) 
{
    if (node == NULL) return;

    inorder(node->l_child);
    printf("%d ", node->value);
    inorder(node->r_child);
}

void postorder(struct Node *node) 
{
    if (node == NULL) return;

    postorder(node->l_child);
    postorder(node->r_child);
    printf("%d ", node->value);
}

int main() 
{
    Insert(30);
    Insert(5);
    Insert(18);
    Insert(40);
    Insert(54);
    preorder(root);
    printf("\n");
}