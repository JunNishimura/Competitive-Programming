#include <iostream>
#define TREESIZE 30
#define NIL -1
using namespace std;

struct Node
{
    int parent = NIL;
    int left_child = NIL;
    int right_child = NIL;
};

Node Tree[TREESIZE];

// Preorder Tree walk by recursion
// (1) print root node (2) move left child (3) move right child
void Preorder(int node_id)
{
    printf(" %d", node_id);                                                   // (1)
    if(Tree[node_id].left_child != NIL)  Preorder(Tree[node_id].left_child);  // (2)
    if(Tree[node_id].right_child != NIL) Preorder(Tree[node_id].right_child); // (3)
}

// Inorder Tree walk by recursion
// (1) move left child (2) print root node (3) move right child
void Inorder(int node_id) 
{
    if(Tree[node_id].left_child != NIL)  Inorder(Tree[node_id].left_child);  // (1)
    printf(" %d", node_id);                                                   // (2)
    if(Tree[node_id].right_child != NIL) Inorder(Tree[node_id].right_child); // (3)
}

// Postorder Tree walk by recursion
// (1) move left child (2) move right child (3) print root node
void Postorder(int node_id) 
{
    if(Tree[node_id].left_child != NIL)  Postorder(Tree[node_id].left_child);  // (1)
    if(Tree[node_id].right_child != NIL) Postorder(Tree[node_id].right_child); // (2)
    printf(" %d", node_id);                                                   // (3)
}

int main() 
{
    int node_num, node_id, l_child, r_child, root = 0;
    scanf("%d", &node_num);

    for (int i = 0; i < node_num; ++i) 
    {
        scanf("%d %d %d", &node_id, &l_child, &r_child);
        Tree[node_id].left_child = l_child;
        Tree[node_id].right_child = r_child;
        // if the node has children, set the node as parent
        if (Tree[node_id].left_child != NIL ) Tree[Tree[node_id].left_child].parent = node_id;
        if (Tree[node_id].right_child != NIL) Tree[Tree[node_id].right_child].parent = node_id;
    }

    // search root
    while (Tree[root].parent != NIL) ++root;

    // execute Tree walk
    printf("Preorder\n");
    Preorder(root);
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    printf("\n");
}