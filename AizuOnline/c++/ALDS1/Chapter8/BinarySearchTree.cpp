#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* parent = nullptr;
    Node* l_child = nullptr;
    Node* r_child = nullptr;
};
Node* root;

// ヌルポインタ自体にアクセスしてはいけません
void InsertNode(int value) 
{
    Node* currentNode = root;
    Node* parent = nullptr;
    Node* newNode = new Node;
    newNode->key = value;

    while(currentNode != nullptr)
    {
        parent = currentNode;
        if (newNode->key <= currentNode->key) currentNode = currentNode->l_child;
        else currentNode = currentNode->r_child;
    }
    newNode->parent = parent;
    if (root == nullptr) root = newNode;
    else if (value <= parent->key) parent->l_child = newNode;
    else parent->r_child = newNode;
}

Node* FindNode(int targetV)
{
    Node* currentNode = root;
    while (currentNode != nullptr)
    {
        if (currentNode->key == targetV) return currentNode;
        else if (currentNode->key < targetV) currentNode = currentNode->r_child;
        else currentNode = currentNode->l_child;
    }
    return nullptr;
}

// 削除するnodeの次の大きさの節点
Node* GetScuccessorNd(Node* delNode)
{
    Node* successor_nd = delNode->r_child;
    while(successor_nd->l_child != nullptr) 
    {
        successor_nd = successor_nd->l_child;
    }
    return successor_nd;
}

void DeleteNode(int value) 
{
    Node* del_key_nd = FindNode(value);
    Node* mem_free_nd;
    Node* ch_mem_free_nd;
    if (del_key_nd->l_child != nullptr && del_key_nd->r_child != nullptr) mem_free_nd = GetScuccessorNd(del_key_nd);
    else mem_free_nd = del_key_nd;

    // set child
    if (mem_free_nd->l_child != nullptr) ch_mem_free_nd = mem_free_nd->l_child;
    else ch_mem_free_nd = mem_free_nd->r_child;

    // if there is a child, update parent pointer
    if (ch_mem_free_nd != nullptr) ch_mem_free_nd->parent = mem_free_nd->parent;

    // update child pointer
    if (mem_free_nd->parent == nullptr) root = ch_mem_free_nd;
    else if (mem_free_nd == mem_free_nd->parent->l_child /*if left*/) mem_free_nd->parent->l_child = ch_mem_free_nd;
    else mem_free_nd->parent->r_child = ch_mem_free_nd;

    // delete key from the tree
    if (del_key_nd != mem_free_nd) del_key_nd->key = mem_free_nd->key;

    // free memory
    delete mem_free_nd;
}   

void Preorder_Print(const Node* currentNode) 
{
    printf(" %d", currentNode->key);
    if (currentNode->l_child != nullptr) Preorder_Print(currentNode->l_child);
    if (currentNode->r_child != nullptr) Preorder_Print(currentNode->r_child);
}

void Inorder_Print(const Node* currentNode) 
{
    if (currentNode->l_child != nullptr) Inorder_Print(currentNode->l_child);
    printf(" %d", currentNode->key);
    if (currentNode->r_child != nullptr) Inorder_Print(currentNode->r_child);
}

int main() 
{
    root = nullptr;
    int node_num, value;
    char order[10];
    scanf("%d", &node_num);
    for (int i = 0; i < node_num; ++i) 
    {
        scanf("%s %d", order, &value);
        if (order[0] == 'i')
        {
            InsertNode(value);
        }
        else if (order[0] == 'f')
        {
            if (FindNode(value) != nullptr) printf("yes\n");
            else printf("no\n");
        }
        else if (order[0] == 'd')
        {
            DeleteNode(value);
        }
        else if (order[0] == 'p')
        {
            Inorder_Print(root);
            printf("\n");
            Preorder_Print(root);
            printf("\n");
        }
    }
}